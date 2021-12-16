#!/bin/bash
# ass_array.sh

declare -A ass_array

# two kinds of declarition
# first
ass_array=([index1]=val1 [index2]=val2)
echo ${ass_array[index1]}
echo ${ass_array[index2]}

# second
declare -A ass_array2
ass_array2[index1]=val1
ass_array2[index2]=val2
echo ${ass_array2[*]}
