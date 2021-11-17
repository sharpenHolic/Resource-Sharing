#!/bin/bash
# read_all_file.sh
# 实现对图片的前缀后缀修改

#########
begin=1    #前缀从1开始
end=".jj" #后缀为png
#########
if test -e data; then 
    cd data
else
    echo "创建一个data目录，放入"
fi

ChangeName(){
    if test -e data; then 
        cd data
    else
        echo "创建一个data目录，放入"
    fi

    for file in `ls`
    do 
        echo $file
        mv $file $begin$end
        let "begin++"
    done
}

ChangeName
