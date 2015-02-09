#!/usr/bin/python2
#!encoding = utf-8

import sys
import subprocess
import gio
import os

reload(sys)
sys.setdefaultencoding('utf-8')

#text command icon subtext
for i in range(1, len(sys.argv)):
    try:
        k = os.popen("find " + os.environ['HOME'] + " -name '*" + sys.argv[i] + "*' 2>/dev/null")
    except:
        sys.exit()
    strs = k.read().splitlines()
    for str in strs:
        icon = gio.File(str).query_info("standard::icon").get_icon().to_string()
        try:
            text = '[' + str.split('/')[-1] + ']'
            command = 'command=xdg-open ' + str
            icon = 'icon=' + icon.split(' ')[2]
            subtext = 'subtext=' + str
        except:
            continue
        print text
        print command
        print icon
        print subtext
