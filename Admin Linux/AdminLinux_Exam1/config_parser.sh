#!/bin/bash

#Display Hostname
echo "Host: $(hostname)"

#Display username
echo "User: $(whoami)"

echo ""

#User argument value
input_key="$1"

#search for key in the first column (case insensetive)
exist=$(cat config.ini | cut -d"=" -f1 | grep -iwc "$input_key")    

#print the value if found
if [ $exist -ge 1 ]; then
	#search for key in the first column (case sensetive)
	exist=$(cut -d"=" -f1 config.ini | grep -wc "$input_key")

	if [ $exist -ge 1 ]; then
		cat config.ini | grep $input_key
	else
		echo "$input_key not found!"
		echo "Do you mean ${input_key,,}? (y: yes, other key: no)"
		read user_choice
		
		if [ "$user_choice" = "y" ]; then
			echo ""
			cat config.ini | grep ${input_key,,}
		fi
	fi
else 
	echo "'$input_key' not found!"
fi
