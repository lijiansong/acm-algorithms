#!/bin/bash

SUB_DIR=("A" "B" "C" "D" "E")
NAMES=("A" "B" "C" "D")

for d in `seq 2014 2019`; do
    for sd in ${SUB_DIR[@]}; do
        echo $d/Round-$sd
        mkdir -p $d/Round-$sd
    done
done
