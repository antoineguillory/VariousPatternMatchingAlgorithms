#!/bin/bash

make naive > /dev/null;
time ./naive dictionnaire.txt;
make naiverapide > /dev/null;
time ./naiverapide dictionnaire.txt;
make naivesentinelle > /dev/null;
time ./naivesentinelle dictionnaire.txt;
make naivestrncmp > /dev/null;
time ./naivestrncmp dictionnaire.txt;

