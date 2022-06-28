#!/bin/sh
setxkbmap us
amixer set Master 37db
brightnessctl s 20%
feh --bg-max '/home/mark/images/wallpaper.jpg'
slstatus &
exec dwm

