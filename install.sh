#!/bin/bash

#terminate on error
set -e

export CFLAGS=-fPIC
export FC=gfortran
export F77=gfortran

install_prefix=$PWD/install
if [ "$UID" == "0" ]; then
  install_prefix=/usr/local
  # anything already installed will automatically ignored
  yum install -y zlib-devel curl-devel netcdf netcdf-devel netcdf-static python-mako numpy
fi

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
