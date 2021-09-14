#!/bin/bash

gcc ex1.c

N=10

for i in $(seq $N)
do
   ./a.out
done