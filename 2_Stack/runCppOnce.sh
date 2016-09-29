#!/bin/bash

CPP=$1
OUT=`echo $CPP | sed 's/.cpp/.out/g'`
g++ -std=gnu++11 -o $OUT $CPP
shift;
./$OUT $@
rm -rf $OUT
