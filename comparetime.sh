#!/bin/bash

cd naive;
make;
cd ..;

time ./naive/naive ./naive/dictionnaire.txt;
time ./naive/naiverapide ./naive/dictionnaire.txt;
time ./naive/naivesentinelle ./naive/dictionnaire.txt;
time ./naive/naivestrncmp ./naive/dictionnaire.txt;
time ./naive/naivestrncmprapide ./naive/dictionnaire.txt;
time ./naive/naivestrncmpsentinelle ./naive/dictionnaire.txt;
