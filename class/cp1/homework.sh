#!/bin/bash

output="usage: $0 <directory_name> <number_of_question> <number_of_bonus>"
reg='^[0-9]+$'

if [ "$#" -ne 3 ]; then
	echo "error: requires 3 arguments"
	echo "$output"
	exit 1
fi

if ! [[ $2 =~ $reg ]] ; then
	echo "error: argument 2 is not a number"
	echo "$output"
	exit 1
fi

if ! [[ $3 =~ $reg ]] ; then
	echo "error: argument 3 is not a number"
	echo "$output"
	exit 1
fi

# create file function
function createFile () {
	if [ ! -e $1 ]; then
		touch $1
	fi
}

dir="$1"

# Create a new directory
if [ ! -d $dir ]; then
	mkdir $dir
fi

# Create Makefile
createFile "$dir/Makefile"

# Copy and rename README
cp "README_TEMPLATE.md" "$dir/README.md"

# Create .c file for questions, .md file for bonus
for i in $( seq 1 $(($2 + $3)) ); do
	if [ $i -lt 10 ]; then
		file="${dir}/${dir}0${i}"
	else
		file="${dir}/${dir}${i}"
	fi

	if [ $i -le $2 ]; then
		ext=".c"
	else
		ext=".md"
	fi

	createFile "${file}${ext}"
done
