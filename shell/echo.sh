#!/bin/bash
# echo.sh

ms="my string"
echo "it is a test"
echo "it \n is \n a \n test"
echo -e "it\nis\na\ntest"
echo "ms is $ms"

# 显示转义字符
echo "\"It is a test\""

# 显示不换行
echo -e "my name is \c" # /c表示不换行
echo "gqxiong"

# 原样输出字符串，不进行转义或取变量(用单引号)
echo '$name\"'

# 显示命令执行结果
echo `date`
echo `ls`
