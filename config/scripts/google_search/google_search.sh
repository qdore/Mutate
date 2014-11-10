#!/bin/bash
echo [$@]
echo "command=xdg-open \"https://www.google.com/search?q=$@\""
echo "icon="
echo "subtext=Search on google for $@"
