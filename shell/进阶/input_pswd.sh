#!/bin/bash
# input_pswd.sh
source time_take.sh
# 倒计时函数
function ReadTime()
{
	tput sc

	count=0
	while true; 
	do 
		if [ $count -lt "$_TIME" ];
		then 
			let count++
			sleep 1
			tput rc
			tput ed
			tput bold
			# tput setb 2
			echo -e "Time: \e[34m `date` \c \e[0m"
		else
			return 0
		fi
	done
}

# 输密码函数
function InputCode()
{
	read -p "Enter: " var	

}



## main

TimeTake ReadTime
time=$?
echo "time is $time"




