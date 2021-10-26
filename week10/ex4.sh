#!/bin/bash

mkdir tmp
echo 1 > tmp/file1
echo 2 > tmp/file2
ln tmp/file1 tmp/link1

gcc ex4.c
./a.out > ex4.txt