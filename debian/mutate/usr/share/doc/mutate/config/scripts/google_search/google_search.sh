#!/bin/bash
echo [$@]
echo "command=xdg-open \"http://www.google.com.hk/webhp?hl=zh-CN#safe=strict&hl=zh-CN&q=$@\""
echo "icon="
echo "subtext=google search $@"
