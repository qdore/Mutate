#!/bin/bash
echo [$@]
echo "command=xdg-open \"http://www.baidu.com/s?wd=$@\""
echo "icon="
echo "subtext=百度搜索 $@"
