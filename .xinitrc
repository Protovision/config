#!/bin/sh
while xsetroot -name " `date +'%a %b %d %Y | %H:%M'` | `vmstat -w 1 1 | awk \"FNR == 3 { printf \\\"%.1f%% RAM | %.1f%% CPU\\\", ((\\\$5 + \\\$6) / (\\\$3 + \\\$4 + \\\$5 + \\\$6)), ((\\\$13 + \\\$14) / (\\\$13 + \\\$14 + \\\$15 + \\\$16) * 100); }\"` "
do
	sleep 1
done &

