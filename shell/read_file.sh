#!/bin/bash
# read_file.sh

echo "$1"
#echo "input a file: "
#read file
readFile(){
    while read line
        do
            echo $line
        done < `ls`
}

readFile
