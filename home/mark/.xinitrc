#!/bin/sh
setxkbmap us
pactl set-sink-volume 0 100%
brightnessctl s 10%
feh --bg-scale '/home/mark/images/wallpaper.png'
slstatus &
exec dwm

