#make sure zlib-devel and curl-devel are installed

export CFLAGS=-fPIC
export FC=gfortran
export F77=gfortran
export LDFLAGS=-lm

tar -xzvf hdf*.tgz
cd hdf*
make clean
./configure --prefix=/usr/local/HDF5 --enable-shared=no
make
make install
cd ..

tar -xzf netcdf*.tgz
cd netcdf*
make clean
./configure --enable-netcdf-4 --with-hdf5=/usr/local/HDF5 --enable-cxx-4 --enable-dap
make
make install
cd ..

cd libcdms
make clean
./configure --enable-dap --with-ncinc=/usr/local/include --with-nclib=/usr/local/lib --prefix=/usr/local
make
make install
cd ..

easy_install -U mako
easy_install -U numpy

for package in cdtime cdms2 regrid2; do
cd $package
python setup.py build
python setup.py install
cd ..




