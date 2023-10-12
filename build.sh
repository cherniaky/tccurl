#!/bin/bash

cd tcc-0.9.27 
make && make install
./dist/bin/tcc -o ../main ../main.c -lm
cd ..