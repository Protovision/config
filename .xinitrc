#!/bin/sh
xrandr --output eDP1 --brightness 0.5
xset b off
xrdb -load /home/mark/.Xresources
while true; do
	DATE_TIME=$(date +'%a %b %d %Y | %H:%M')
	RAM=$(free | awk "FNR == 2 { printf \"x = %s / %s * 100; scale = 0; x / 1\\n\", \$3, \$2 }" | bc -ql)
	CPU=$(printf "100 - $(vmstat 1 1 | awk "FNR == 3 { print \$15 }")\n" | bc -ql)
	BAT=$(cat /sys/class/power_supply/BAT0/capacity)
	xsetroot -name " $DATE_TIME | $RAM% RAM | $CPU% CPU | $BAT% BAT "
	sleep 2
done &
exec dwm

