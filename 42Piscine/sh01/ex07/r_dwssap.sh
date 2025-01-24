#!/bin/sh
cat /etc/passwd | sed '/^#/d' | awk 'NR % 2 == 0' | cut -d: -f1 | rev | sort -r | awk -v FT_LINE1="$FT_LINE1" -v FT_LINE2="$FT_LINE2" 'NR >= FT_LINE1 && NR <= FT_LINE2' | paste -sd ", " - | sed 's/$/./'
