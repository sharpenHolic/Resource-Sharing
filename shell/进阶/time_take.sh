#!/bin/bash
# time_take.sh

function TimeTake()
{
	start=$(date +%s)

	$1

	end=$(date +%s)
	diff=$(( end - start))

	echo "time takes: $diff s"
	return $diff
}

