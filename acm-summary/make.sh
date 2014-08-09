#!/bin/bash

cd tex/
OUT=$1
FILE=$1.tex
xelatex $FILE 
rm -f $OUT.log $OUT.aux
mv $OUT.pdf ../pdf/
open ../pdf/$OUT.pdf
