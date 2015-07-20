#!/bin/bash
echo [$@]
echo "command=xdg-open \"https://www.youtube.com/results?search_query=$@\""
echo "icon="
echo "subtext=Search on Youtube for $@"
