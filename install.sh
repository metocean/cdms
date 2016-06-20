#
# Dependencies
#
# libpng-devel jasper-devel zlib-devel curl-devel python-mako bison flex

python=$(which python)
if [ "$1" != "" ]; then
  python=$1
fi 
python_config=$(which python-config)

build_dir=`pwd`/build
install_dir=`pwd`/install #the actual place into which cdms is installed can be found at the end of the script


#debugging: export CFLAGS="-fPIC -g "
export CFLAGS="-fPIC"
export FC=gfortran
export F77=gfortran
export LDFLAGS=-lm 

python_prefix=$($python_config --prefix)
python_version=$($python --version 2>&1 | grep -E -o "[0-9]\.[0-9]")
python_lib_path=$install_dir/lib/python$python_version/site-packages
python_install_path=$python_prefix/lib/python$python_version/site-packages
export PYTHONPATH=$python_lib_path

mkdir -p $build_dir

if [[ ! -s $install_dir/lib/libdf.a || ! -s $install_dir/lib/libmfhdf.a || ! -s $install_dir/include/hdf.h ]]; then
  echo "Installing HDF-4"
  pushd $build_dir
  tar -xzf ../hdf-4.2.5.tar.gz
  cd hdf-4.2.5
  make clean
  ./configure --prefix=$install_dir --disable-shared --disable-fortran --disable-netcdf
  make
  make install
  popd
fi

if [[ ! -s $install_dir/lib/libhdf5.a || ! -s $install_dir/include/H5FDcore.h ]]; then
  echo "Installing HDF-5"
  pushd $build_dir
  tar -xzf ../hdf5-1.8.3.tar.gz
  cd hdf5-1.8.3
  make clean
  ./configure --prefix=$install_dir --enable-shared=no
  make
  make install
  popd
fi


if [[ ! -s $install_dir/lib/libnetcdf.a || ! -s $install_dir/include/netcdf.h ]]; then
  echo "Installing netcdf"
  pushd $build_dir
  tar -xzf ../netcdf-4.1.1.tar.gz
  cd netcdf-4.1.1
  make clean
  ./configure --prefix=$install_dir --enable-netcdf-4 --with-hdf5=$install_dir --enable-cxx-4 --enable-dap
  make
  make install
  popd
fi

 
 
if [[ ! -s $install_dir/lib/libgrib2c.a || ! -s $install_dir/include/grib2.h ]]; then
  echo "Installing grib2clib"
  pushd $build_dir
  tar -xzf ../g2clib-1.4.0.tar.gz
  cd g2clib-1.4.0
  export CFLAGS=-fPIC
  make all
  mkdir -p $install_dir/lib/
  cp libgrib2c.a $install_dir/lib/
  mkdir -p $install_dir/include/
  cp grib2.h $install_dir/include/
  popd
fi

echo "Installing libcdms"
pushd libcdms
make distclean
./configure CXX=g++ --enable-dap --prefix=$install_dir \
            --with-ncinc=$install_dir/include --with-nclib=$install_dir/lib \
            --with-hdflib=$install_dir/lib \
            --with-grib2inc=$install_dir/include
make
mkdir --parents $install_dir/man/man3
make install
popd

mkdir -p $python_lib_path

if [[ ! -s $python_lib_path/numpy ]]; then
  echo "Installing numpy"
  pushd $build_dir
  tar -xzf ../numpy-1.6.1.tar.gz
  cd numpy-1.6.1
  cp ../../numpy-site.cfg site.cfg
  $python_prefix/bin/python setup.py install --prefix $install_dir --install-lib=$install_dir/lib/python$python_version/site-packages
  popd
fi

for package in cdtime cdms2 regrid2 regrid; do
  echo "Installing $package"
  cd $package
  rm -rf build
  $python setup.py install --force --prefix=$install_dir --install-lib=$install_dir/lib/python$python_version/site-packages
  cd ..
done

sudo cp -r $python_lib_path/* $python_install_path/
