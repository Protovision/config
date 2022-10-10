#!/bin/sh
setxkbmap us
pactl set-sink-volume 0 100%
brightnessctl s 20%
feh --bg-scale '/home/mark/images/wallpaper.png'
slstatus &
exec dwm

