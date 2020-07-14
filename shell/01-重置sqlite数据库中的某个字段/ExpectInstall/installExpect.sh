#/bin/bash

# install tcl
echo "Untar tcl..."
tar zxf tcl8.4.19-src.tar.gz 
echo "Install tcl..."
cd tcl8.4.19/unix  
sudo ./configure > /dev/null 2>&1
sudo make  > /dev/null 2>&1
sudo make install  > /dev/null 2>&1
echo "Tcl installed."
sleep 1

#install expect
cd ../../
echo "Untar expect..."
tar zxf expect5.45.tar.gz
echo "Install expect..."
cd expect5.45
sudo ./configure --with-tclinclude=../tcl8.4.19/generic --with-tclconfig=/usr/local/lib/  > /dev/null 2>&1
sudo make  > /dev/null 2>&1
sudo make install  > /dev/null 2>&1

echo "expect installed."

