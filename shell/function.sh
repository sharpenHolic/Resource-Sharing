#!/bin/bash
# function.sh

demoFun(){
    echo "这是我的第一个 shell 函数!"
}
echo "-----函数开始执行-----"
demoFun
echo "-----函数执行完毕-----"

# has a return value
funWithReturn(){
    echo "这个函数会对输入的两个数字进行相加运算..."
    echo "输入第一个数字: "
    read aNum
    echo "输入第二个数字: "
    read anotherNum
    echo "两个数字分别为 $aNum 和 $anotherNum !"
    return $(($aNum+$anotherNum))
}
funWithReturn
echo "输入的两个数字之和为 $? !"


# has input value

funWithInput(){
	echo "函数第1个参数：$1"
	echo "函数第2个参数：$2"
	echo "函数第3个参数：$3"
	echo "函数第4个参数：$4"
}
echo "传递参数"
funWithInput a b c de g
echo "传递参数"


