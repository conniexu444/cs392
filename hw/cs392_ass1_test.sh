#!/bin/sh


gcc -fPIC -O0 -c cs392_printf.c -o cs392_printf.o
gcc -shared -fPIC -o libcs392_io.so  cs392_printf.o
gcc -O0 -o cs392_ass1 main.c libcs392_io.so

export LD_LIBRARY_PATH=$PWD
./cs392_ass1

