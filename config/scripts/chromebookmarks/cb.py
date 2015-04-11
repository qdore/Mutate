#!/usr/bin/python
#!encoding = utf-8

import json
from pprint import pprint
import sys
import os
from ConfigParser import SafeConfigParser
from os.path import expanduser
home = expanduser("~")

parser = SafeConfigParser()
parser.read(home+'/.config/Mutate/scripts/chromebookmarks/config.ini') 
# parser.read('./config.ini') 
    
config = {}
config['bookmarksPath'] = parser.get('General', 'bookmarksPath')
config['onlyBookmarksBar'] = parser.get('General', 'onlyBookmarksBar')
config['spaceMeaning'] = parser.get('General', 'spaceMeaning')

matches = []
matches_len = 0

query = []


if len(sys.argv)>1:
    for i in range(1, len(sys.argv)):
        temp = sys.argv[i].split(' ')
        for j in range(0, len(temp)):
            if len(temp)>0:
                query.append(temp[j].strip())

def findBookmarksPath():
    f = os.popen('locate google-chrome | grep Bookmarks')
    res = f.read()
    res = res.split('\n')
    if len(res)==0:
        errorprint()
        sys.exit(-1)
    if len(res) > 1:
        for i in range(0, len(res)):
            if res[i][-9:] == 'Bookmarks':
                return res[i]
    return ''
                

def matching(o, q):
    global matches_len
    if matches_len >=10:
        return False
#    o['name'] = o['name'].encode('utf-8')
#    o['url'] = o['url'].encode('utf-8')
    if q.lower() in o['name'].lower():
        return True
    if q.lower() in o['url'].lower():
        return True
    return False

def findRec(o, path, force=False):
    global matches
    global matches_len
    global config
    if matches_len >=10:
        return
    o['dirpath'] = ''+path
    if o['type'] == 'folder':
        for i in range(0, len(o['children'])):
            #findRec(o['children'][i], path+''+o['name']+'/')
            findRec(o['children'][i], o['name'], force)
    else:
        if config['spaceMeaning'] == 'AND':
            temp = True
            for i in range(0, len(query)):
                temp = temp and matching(o,query[i])
            if temp:
                matches.append(o)
                matches_len += 1
        elif config['spaceMeaning'] == 'OR':
            temp = False
            for i in range(0, len(query)):
                temp = temp or matching(o,query[i])
            if temp:
                matches.append(o)
                matches_len += 1
        else:
            errorprint()
            sys.exit(-2)


def limitString(string, limit):
    if len(string) > limit:
        string = string[:(limit-3)]+'...'
    return string

def prettyprint(o):
    output({
        'name':limitString(o['name'],20).encode('utf-8'),
        'command': "xdg-open \""+o['url'].strip().encode('utf-8')+"\"",
        'subtext':o['url'].strip().encode('utf-8')
    })



def queryprint():
    n = ', '.join(query)
    outpu({'name':n, 'subtext': 'searching...'})

def nofoundprint():
    output({'name': 'Nothing found', 'subtext': ''})

def errorprint():
    output({'name': 'Something went wrong', 'subtext': 'config error'})

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


if len(config['bookmarksPath']) == 0:
    config['bookmarksPath'] = findBookmarksPath()
    if len(config['bookmarksPath']) == 0:
        errorprint()
        sys.exit(-1)

with open(config['bookmarksPath']) as data_file:
    data = json.load(data_file)
    if config['onlyBookmarksBar']:
        data = data['roots']['bookmark_bar']
    else:
        data = data['roots']

    data['dirpath'] = ''
    findRec(data, '')
    maxlen = 10
    if matches_len < 10:
        maxlen = matches_len
    for i in range(0,maxlen):
        prettyprint(matches[i])
    if matches_len == 0:
        nofoundprint()
