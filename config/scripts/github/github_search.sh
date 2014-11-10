#!/bin/bash
echo [$@]
echo "command=xdg-open \"http://github.com/search?q=$@\""
echo "icon="
echo "subtext=Search on github for $@"
