Mutate - An award-winning productivity application
======
Mutate is a simple launcher inspired by Alfred (OS X app) for Linux. Be more productive with hotkeys, keywords and file actions at your fingertips.

![url demo](http://i.imgur.com/bnBvfgw.png)


## Dependencies
* boost-regex
* QT5
* GTK2 (for application icon lookup)
* ICU
* libsm
* libxkbcommon


## Installing
### From Repository
#### Ubuntu PPA (thanks http://www.noobslab.com)
NOTE: PPA has changed, please delete ```wei-qianghb/mutate``` first

```bash
sudo add-apt-repository ppa:mutate/ppa
sudo apt-get update
sudo apt-get install mutate
```


#### Arch Linux AUR
```bash
curl -O https://aur.archlinux.org/cgit/aur.git/snapshot/mutate-git.tar.gz
tar xvf mutate-git.tar.gz
cd mutate-git
makepkg -si
```

### From Package Release
#### Ubuntu
```bash
wget https://github.com/qdore/Mutate/releases/download/v2.3/Mutate-2.3.deb
sudo apt-get install gdebi
sudo gdebi Mutate-2.3.deb
```

#### Fedora
```bash
sudo yum -y install https://github.com/qdore/Mutate/releases/download/v2.3/Mutate-2.3-0.fc21.x86_64.rpm
/usr/share/mutate/setup
```


### From Source
#### Ubuntu
Install needed dependencies:
```bash
sudo apt-get install build-essential qt5-qmake qt5-default libgtk2.0-dev libqt5x11extras5-dev libboost-regex-dev
```

Then download and compile:
```bash
git clone https://github.com/qdore/Mutate.git
cd Mutate/src
qmake
make
```

Then install it:
```bash
sudo make install
cd ..
sudo cp info/mutate.png /usr/share/icons
sudo cp info/Mutate.desktop /usr/share/applications
mkdir -p ~/.config/Mutate
cp -R config/* ~/.config/Mutate
chmod -R a+x ~/.config/Mutate/scripts
chmod -R a+w ~/.config/Mutate
sed -i "s|{home}|$HOME|g" ~/.config/Mutate/config.ini
```

#### Fedora (Thanks retspen)
Install needed dependencies:
```bash
sudo yum -y install rpmdevtools yum-utils
rpmdev-setuptree
```

Download and compile:
```bash
cd ~/rpmbuild/SOURCES
wget https://raw.githubusercontent.com/qdore/Mutate/master/rpm/mutate.spec
wget https://github.com/qdore/Mutate/archive/master.zip
sudo yum-builddep -y mutate.spec
rpmbuild -bb mutate.spec
```

Then install it:
```bash
sudo yum -y install ~/rpmbuild/RPMS/x86_64/Mutate-2.3-0.fc21.x86_64.rpm
/usr/share/mutate/setup
```


## Features
Loaded with features to increase your productivity.

### Find Applications & Files
![applications demo](http://i.imgur.com/dyNHVwU.png)

### Find Files
![files demo](http://i.imgur.com/4Jx878l.png)

### Calculate(thanks t413)
```
NOTE:You must install sympy first:
sudo apt-get install python-pip
sudo pip install sympy
```

![calculate_demo](http://i.imgur.com/py09Ewv.png)

### Kill Processes
![killprocess demo](http://i.imgur.com/XSciIex.png)

### Google Translate
Select some words use your mouse, then press Ctrl+T (user configurable):
![translate demo](http://i.imgur.com/kB4YSqU.jpg)

Or type 'tr' and some words:
![translate demo](http://i.imgur.com/gycjZeY.png)

### Quickly Search the Web
#### Google Search
![google demo](http://i.imgur.com/oRtXJBu.png)

#### Github Search
![github demo](http://i.imgur.com/oIVCSqS.png)

You can also add other keywords such as wiki, twitter or youtube.

### Open URLs
![url demo](http://i.imgur.com/2JFFMZz.png)

### Quickly Shut Down, Log Out, or Reboot
![shutdown demo](http://i.imgur.com/yvyyUDb.png)


## Preferences
Type preference to open the preferences window.

The first row is for the hotkey to open Mutate. The default is Ctrl+D.

Other rows configure the path, icon path, hotkey, and keyword for different 
scritps. For example, google_translate's hotkey is configured as Ctrl+T, and 
when you press it Mutate will type 'tr' and the selected text.

```
NOTE:If you want use key 'super' as your hotkey, type Meta will help.
```

![preferemce demo](http://i.imgur.com/1hHLY6r.png)

## Custom Scripts
When you type "tr work" in the line editor, Mutate will execute 
./google_translate.py in the background.

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

For the first item, it will show "工作" in the first row, and "work" in the second row, if you don't Specify icon's address, it will show the script's original icon.

About command:
command can be shell command, it means if you enter this item it will do this shell command.Except shell command, it can be "copy" to copy this item's text to clipboard.

It isn't hard to know what does it mean, and it is also very easy to write a script.
In the "~/.config/Mutate/scripts",it has some scripts for examples.

## Contact: wei.qianghb@foxmail.com

