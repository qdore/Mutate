#!/usr/bin/python2
#!encoding = utf-8

import json
from pprint import pprint
import sys
import os
import time

def printcmd(c):
    output({
        'name': c[0],
        'command':'kill -9 '+c[1],
        'subtext':'PID: '+c[1]+', CPU: '+c[2]+'%, RAM: '+c[3]+'%, USER:'+c[4]
        })

def nofoundprint():
    output({'name': 'Nothing found', 'subtext': ''})

def errorprint():
    output({'name': 'Something went wrong', 'subtext': 'config error'})

def shortprint():
    output({'name': 'Usage', 'subtext': '[c] ordered by %CPU, [m] ordered by %MEM'})
    output({'name': 'top c', 'subtext': 'sort by %CPU'})
    output({'name': 'top m', 'subtext': 'sort by %MEM'})

defaultoutput = {
    'name' : '',
    'command' : '',
    'icon' : '',
    'subtext' : ''
}
def output(o):
    temp = defaultoutput.copy()
    temp.update(o)
    print "["+temp['name']+"]"
    print "command="+temp['command']
    print "icon="+temp['icon']
    print "subtext="+temp['subtext']


if len(sys.argv) == 0:
    errorprint()
    sys.exit(-1)
if len(sys.argv) == 1:
    shortprint()
    sys.exit(-1)
if len(sys.argv) != 2:
    shortprint()
    sys.exit(-1)

lines = []
cmds = []
if sys.argv[1] == 'c':
    f = os.popen('ps axo comm,pid,pcpu,pmem,user k -pcpu |head')
elif sys.argv[1] == 'm':
    f = os.popen('ps axo comm,pid,pcpu,pmem,user k -pmem |head')
else:
    shortprint()
    sys.exit(0)

res = f.read()
res = res.split('\n')

if len(res)==0:
    errorprint()
    sys.exit(-1)

for i in range(1, len(res)):
    cmds.append(res[i].split())
del cmds[-1]

for i in range(0, len(cmds)):
    printcmd(cmds[i])
