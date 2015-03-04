#!/bin/bash          
path=$(pwd)

if [ $1 = "tp" ]; then
    cd "$path/../$1/tp$2"
else
    if [ $1 = "pratica" ]; then
        cd "$path/../$1/pratica$2"
    fi
fi

for FILE in `ls`;do
    if [ ${FILE: -2} = ".c" ] || [ ${FILE: -2} = ".h" ] || [ $FILE = "Makefile" ]; then
        files="${files} $FILE"
    fi
done

zip tp$2.zip `echo $files`