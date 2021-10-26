#!/bin/bash

echo "ososos" > ../week01/file.txt
link ../week01/file.txt _ex2.txt

inodenumber=($(ls -i ../week01/file.txt))

find ../ -inum "${inodenumber}" >> ex2.txt

# find ../ -inum "${inodenumber}" -exec rm {} \; # commented to not to delete files