#!/bin/bash

cd tcc-0.9.27 
make && make install
cd ..
tcc -o main main.c -lm