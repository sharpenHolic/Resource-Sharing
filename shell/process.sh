#!/bin/bash
# process.sh

# if else
if test -e ./file; then 
    echo "file exsist"
else
    echo "no file"
fi

# for 
for loop in 1 2 3 4 5
do
    echo "The value is: $loop"
done

for str in This is a string
do
    echo $str
done


# while 
i=1
while(($i<=5))
do
	echo $i
	let "i++"
done

echo '按下 <CTRL-D> 退出'
echo -n '输入你最喜欢的网站名: '
while read FILM
do
    echo "是的！$FILM 是一个好网站"
done

# until loop
a=0

until [ ! $a -lt 10 ]
do
   echo $a
   a=`expr $a + 1` # 和这个一样的效果let "a++"
done

# case ... esac
site="runoob"

case "$site" in
   "runoob") echo "菜鸟教程"
   ;;
   "google") echo "Google 搜索"
   ;;
   "taobao") echo "淘宝网"
   ;;
esac

# break
while :
do 
	echo -n "输入0-5之间的数字："
	read aNum
	case $aNum in
		1|2|3|4|5) echo "你输入的数字为:$aNum"
		;;
		*) echo "游戏结束"
			break
		;;
	esac
done





