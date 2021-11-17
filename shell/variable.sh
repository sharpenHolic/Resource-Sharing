#!/bin/bash
echo "Hello World !"

###########定义变量############
# 1 命名只能使用英文字母，数字和下划线，首个字符不能以数字开头
# 2 中间不能有空格，可以使用下划线 _
# 3 不能使用标点符号
# 4 不能使用bash里的关键字（可用help命令查看保留关键字）
name="runoob.com"
echo $name
echo ${name}
for file in `ls`; do 
	a=$file 
	echo $a
done

# 只读变量
name_read_only="read_only"
readonly name_read_only
# name_read_only="try_to_change"

# 删除变量
# 不能删除只读变量
unset name
echo "after unset:"$name
###########################

###########字符串##########
# 单引号
# 单引号里的任何字符都会原样输出，单引号字符串中的变量是无效的；
# 单引号字串中不能出现单独一个的单引号（对单引号使用转义符后也不行），但可成对出现，作为字符串拼接使用。
str='this is a string'

# 双引号
# 双引号里可以有变量
# 双引号里可以出现转义字符
your_name="runoob"
str="Hello, I know you are \"$your_name\"! \n"
echo -e $str

# 拼接字符串
your_name="runoob"
# 使用双引号拼接
greeting="hello, "$your_name" !"
greeting_1="hello, ${your_name} !"
echo $greeting  $greeting_1
# 使用单引号拼接
greeting_2='hello, '$your_name' !'
greeting_3='hello, ${your_name} !'
echo $greeting_2  $greeting_3

# 获取字符串长度
string="abcd"
echo ${#string} #输出 4

# 提取子字符串
string="runoob is a great site"
echo ${string:1:4} # 输出 unoo

# 查找子字符串
# 输出的是位置，从1开始
string="runoob is a great site"
echo `expr index "$string" ion`  # 输出 3，因为n先出现
echo `expr index "$string" io`  # 输出 4，因为o先出现
###########################

###########数组##########
# bash支持一维数组（不支持多维数组），并且没有限定数组的大小。
# 类似于 C 语言，数组元素的下标由 0 开始编号。
# 获取数组中的元素要利用下标，下标可以是整数或算术表达式，
# 其值应大于或等于 0。
array=(1 2 3 4 5)
# 读取数组
echo ${array[1]} # 输出： 2
# 使用 @ 符号可以获取数组中的所有元素
echo ${array[@]} # 输出：1 2 3 4 5
# 怎么遍历数组？
# 获取数组的长度
# 取得数组元素的个数
echo ${#array[@]} # 5
# 或者
echo ${#array[*]} # 5
# 取得数组单个元素的长度
echo ${#array[1]} # 1
###########################

###########字符串##########

echo "Shell 传递参数实例！";
echo "执行的文件名：$0";
echo "第一个参数为：$1";
echo "第二个参数为：$2";
echo "第三个参数为：$3";

###########################



