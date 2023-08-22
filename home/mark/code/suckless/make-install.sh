#!/bin/sh
for d in dmenu dwm slstatus st
do
	sudo make -C $d install
done

