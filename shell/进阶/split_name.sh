#!/bin/bash
# split_name.sh

URL="www.google.com"

# use % 
echo ${URL%.*} # 去除*.所匹配的最右边内容

# use %%
echo ${URL%%.*} # 去除*.从最右边内容一直到左边的内容，贪婪

# use #
echo ${URL#*.} # 去除*.所匹配的最左边内容

# use ##
echo ${URL##*.} # 将最左边匹配内容到最右边的*.移除





