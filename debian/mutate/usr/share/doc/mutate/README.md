Mutate - An award-winning productivity application
======

Mutate is a simple quick start tool inspired by Alfred(OS X app) for ubuntu.Be more productive with hotkeys, keywords and file actions at your fingertips.
 
    NOTE: For now I have just tested on Ubuntu 14.04 amd64, others will be test later.

##Loaded with features to increase your productivity
----
###Find Applications & Files
![applications demo](http://i.imgur.com/dyNHVwU.png)
###Find Files
![files demo](http://i.imgur.com/4Jx878l.png)
###kill process
![killprocess demo](http://i.imgur.com/XSciIex.png)
###google translate
####Select some words use your mouse, than press ctrl+t(you can define it )
![translate demo](http://i.imgur.com/kB4YSqU.jpg)
####or input 'tr' and some words
![translate demo](http://i.imgur.com/gycjZeY.png)
###Quick-Search the Web
####google search
![google demo](http://i.imgur.com/oRtXJBu.png)
####github search
![github demo](http://i.imgur.com/oIVCSqS.png)
You can add other keywods such as keywords like wiki, twitter or youtube.
###open url
![url demo](http://i.imgur.com/2JFFMZz.png)
####quickly shut down or log out or reboot
![shutdown demo](http://i.imgur.com/yvyyUDb.png)

##How to install:

	make && make install(without sudo!)
	
	Then you can open it use Dash.

![url demo](http://i.imgur.com/bnBvfgw.png)

##Preference:
####Type preference to open the setting widget
The first row means default hotkey to open mutate is Ctrl+D,also you can redefine it.
Other scripts's keyword, take google_translate for example.If you press Ctrl+T,it will type 'tr ' and the mouse selected text into the line editor.
![preferemce demo](http://i.imgur.com/1hHLY6r.png)
####How to write scripts
When you type "tr work" in the line editor,mutate will execute ./google_translate.py in the backgrouder.
```
./google_translate.py work
[工作]
command=copy
icon=
subtext=work
[做工]
command=copy
icon=
subtext=work, do manual work
[办事]
command=copy
icon=
subtext=work, handle affairs
[干]
command=copy
icon=
subtext=dry, do, concern, be concerned with, have to do with, work
[活]
command=copy
icon=
subtext=live, save, subsist, work
[事]
command=copy
icon=
subtext=be engaged, serve, wait on, wait upon, work
[运转]
command=copy
icon=
subtext=operate, revolve, turn around, work
[在职]
command=copy
icon=
subtext=hold a post, work
[做事]
command=copy
icon=
subtext=work, act, handle affairs, have a job
```
It isn't hard to know what does it mean, and it is also very easy to write a script.
In the "~/.config/Mutate/scripts",it has some scripts for examples.
###Contact: wei.qianghb@foxmail.com

