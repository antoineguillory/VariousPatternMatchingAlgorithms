#!/bin/bash

cd naive;
make;
cd ..;

time ./naive/naive dictionnaire.txt;
time ./naive/naiverapide dictionnaire.txt;
time ./naive/naivesentinelle dictionnaire.txt;
time ./naive/naivestrncmp dictionnaire.txt;
time ./naive/naivestrncmprapide dictionnaire.txt;
time ./naive/naivestrncmpsentinelle dictionnaire.txt;
