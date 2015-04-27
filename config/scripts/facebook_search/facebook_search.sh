#!/bin/bash
echo [$@]
echo "command=xdg-open \"https://www.facebook.com/search/str/$@\"/keywords_top"
echo "icon="
echo "subtext=Search on facebook for $@"
