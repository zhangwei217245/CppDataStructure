#!/bin/bash

CPP=$1
OUT=`echo $CPP | sed 's/.cpp/.out/g'`
g++ -o $OUT $CPP
shift;
./$OUT $@
rm -rf $OUT


#http://proprogramming.org/c-program-to-implement-avl-tree/
#http://kukuruku.co/hub/cpp/avl-trees
