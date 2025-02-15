#!/bin/sh

feh --bg-scale /usr/share/pdwm/wallpaper.png & disown
slstatus & disown
exec dwm
