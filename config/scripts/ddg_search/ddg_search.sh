#!/bin/bash
echo [$@]
echo "command=xdg-open \"https://duckduckgo.com/?q=$@\""
echo "icon="
echo "subtext=Search on duckduckGo for $@"
