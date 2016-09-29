#!/bin/bash

CSRC=$1
OUT=`echo $CSRC | sed 's/.c/.out/g'`
g++ -o $OUT $CSRC
shift;
./$OUT $@
rm -rf $OUT
