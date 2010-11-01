#
# Dependencies
#
# Anything already installed will automatically be ignored
# sudo yum install -y zlib-devel curl-devel python-mako




build_dir=`pwd`/build
install_dir=`pwd`/install #the actual place into which cdms is installed can be found at the end of the script


#debugging: export CFLAGS="-fPIC -g "
export CFLAGS="-fPIC"
export FC=gfortran
export F77=gfortran
export LDFLAGS=-lm



mkdir -p $build_dir

if [[ ! -s $install_dir/lib/libhdf5.a || ! -s $install_dir/include/H5FDcore.h ]]; then
  echo "Installing HDF-5"
  pushd $build_dir
  tar -xzvf ../hdf5-1.8.3.tar.gz
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
  tar -xzf ../g2clib-1.2.0.tar.gz
  cd g2clib-1.2.0
  patch -i ../../g2clib-1.2.0-makefile.patch
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


python_version=$(python --version 2>&1 | grep -E -o "[0-9]\.[0-9]")
python_lib_path=$install_dir/lib/python$python_version/site-packages
export PYTHONPATH=$python_lib_path
mkdir -p $python_lib_path

if [[ ! -s $python_lib_path/numpy-1.4.1-py$python_version-linux-x86_64.egg ]]; then
  echo "Installing numpy"
  easy_install --prefix $install_dir numpy-1.4.1.tar.gz
fi

for package in cdtime cdms2 regrid2; do
  echo "Installing $package"
  cd $package
  rm -rf build
  python setup.py install --force --prefix=$install_dir --install-lib=$install_dir/lib/python$python_version/site-packages
  cd ..
done


sudo cp -r  install/lib/python$python_version/site-packages/* /usr/lib64/python$python_version/site-packages/
