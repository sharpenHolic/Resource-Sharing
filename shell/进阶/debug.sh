#!/bin/bash
# debug.sh

function DEBUG()
{
	[ "$_DEBUG" == "on" ] && $@ || : # 三元运算符，&&优先级高于||，&&成功后面截断 
}

for i in {1..10}
do 
	DEBUG echo $i
done


