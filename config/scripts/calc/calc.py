#!/usr/bin/python2
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
cmd = ""
for i in range(1, len(sys.argv)):
    cmd = cmd + sys.argv[i]
expr = sympify(cmd)
print '[' + str(expr) + ']'
print "command=copy"
print "icon="
print "subtext=copy result to clipboard"
