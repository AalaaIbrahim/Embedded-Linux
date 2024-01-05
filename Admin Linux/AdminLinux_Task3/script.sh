#!/bin/bash

if [ $(ls -a ~ | grep ".bashrc" | wc -l) ]; then
	if [ $(cat ~/.bashrc | grep "HELLO" | wc -w) == 0 ]; then
		echo 'export HELLO=$HOSTNAME' >> ~/.bashrc
	fi
	if [ $(cat ~/.bashrc | grep "LOCAL" | wc -l) == 0 ]; then
		echo 'LOCAL=$(whoami)' >> ~/.bashrc
	fi

	gnome-terminal
else
	echo ".bashrc not found."
fi
