#!/bin/bash

CPP=$1
OUT=`echo $CPP | sed 's/.cpp/.out/g'`
g++ -o $OUT $CPP
