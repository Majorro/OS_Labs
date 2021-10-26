#!/bin/bash

echo ososos > _ex3.txt
chmod -x _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod 707 _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod -R g=u _ex3.txt
ls -l _ex3.txt >> ex3.txt

660 == -rw-rw----
775 == -rwxrwxr-x
777 == -rwxrwxrwx