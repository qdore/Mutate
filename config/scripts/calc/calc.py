#!/usr/bin/python
#!encoding = utf-8

import sys
reload(sys)
sys.setdefaultencoding('utf-8')

try:
    from sympy import *
    x, y, z = symbols("x y z")
except:
    print "[..?]\ncommand=echo yo\nicon=\nsubtext=install *sympy* for calculator!"
    sys.exit(0)

for i in range(1, len(sys.argv)):
    cmd = sys.argv[i]

    expr = sympify(cmd)

    print '[' + str(expr) + ']'
    print "command=echo -n '"+str(expr)+"' | xclip -sel clip"
    print "icon="
    print "subtext=copy result to clipboard"
