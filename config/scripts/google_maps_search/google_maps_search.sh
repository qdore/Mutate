#!/bin/bash
echo [$@]
echo "command=xdg-open \"https://www.google.com/maps/place/$@\"/"
echo "icon="
echo "subtext=Search on google maps for $@"
