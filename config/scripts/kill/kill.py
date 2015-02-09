#!/usr/bin/python2

#text command icon subtext
import subprocess, gio, sys
apps = gio.app_info_get_all()
for i in range(1, len(sys.argv)):
    try:
        k = subprocess.check_output("ps -A -o pid -o %cpu -o comm | grep -i [^/]" + sys.argv[i] + "[^/]*$", shell = True)
    except:
        sys.exit()
    for j in k.splitlines():
        result_s = j.split(' ')
        result = []
        for result_tmp in result_s:
            if result_tmp != '':
                result.append(result_tmp)
        print '[' + result[2] + ']'
        print 'command=kill -9 ' + result[0]
        icon = ""
        for app in apps:
            if app.get_executable() == result[2]:
                try:
                    icon = app.get_icon().to_string()
                except:
                    icon = ""
        if icon == "":
            icon = "/usr/share/icons/gnome/48x48/mimetypes/application-x-executable.png"
        print "icon=" + icon
        try:
            temp = subprocess.check_output("which " + result[2], shell=True)
            print "subtext=" + result[1] + '% CPU @ ' + temp
        except:
            print "subtext=" + result[1] + '% CPU @ ' + result[2]
