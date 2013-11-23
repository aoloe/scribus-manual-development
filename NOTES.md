# Notes

## Ubuntu
To compile and run scribus without problem in Ubuntu 12.10 you may need to set the  paths to python libs or add them to cmake command line, otherwise python3 libs will be preferred over python2

cmake ../Scribus -DWANT_SYSTEM_CAIRO=1 -DCMAKE_INSTALL_PREFIX=../Scribus-bin -DPYTHON_LIBRARY=/usr/lib/libpython2.7.so -DPYTHON_INCLUDE_DIR=/usr/include/python2.7
