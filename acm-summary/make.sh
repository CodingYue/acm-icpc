#!/bin/bash

cnt=0
for var in $*
do
	cnt=$((cnt+1))
done
for var in $*
do
	OUT=${var%.*}
	FILE=$OUT.tex
	echo $OUT
	if [ $cnt -eq 1 ] ; then
		xelatex $FILE
	else
		xelatex $FILE > /dev/null
	fi
done
rm -f *.log *.aux
rm -f template.pdf
mv *.pdf pdf/
if [ $cnt -eq 1 ] ; then
	OUT=${1%.*}
	X=${OUT##*/}
	open pdf/$X.pdf
fi
