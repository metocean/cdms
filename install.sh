#!/bin/bash

#terminate on error
set -e

export CFLAGS=-fPIC
export FC=gfortran
export F77=gfortran

install_prefix=$PWD/install
yum_install=yum
if [ "$UID" != "0" ]; then
  install_prefix=/usr/local
  yum_install=sudo yum
fi
 
# anything already installed will automatically ignored
$yum_install install -y zlib-devel curl-devel netcdf netcdf-devel netcdf-static python-mako numpy

mkdir -p $install_prefix/bin
mkdir -p $install_prefix/lib
mkdir -p $install_prefix/include
mkdir -p $install_prefix/man/man3

echo "Installing libcdms"
cd libcdms
make -i clean
./configure --prefix=$install_prefix --disable-ql --disable-dap --disable-hdf --disable-drs --with-nclib=/usr/lib64 --with-ncinc=/usr/include
make
make install
cd ..


for package in cdtime cdms2 regrid2; do
  echo "Installing $package"
  cd $package
  python setup.py install --prefix=$install_prefix
  cd ..
done
