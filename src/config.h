#ifndef CONFIG_H
#define CONFIG_H
#include <QProcess>
#include <sstream>
#include <string>
#include <QDesktopWidget>
#include <QApplication>
#include <QIcon>
#include <QStringList>

#define rowsize 51
#define beginheight 125 //125 -> 94
#define iconsize 42
#define listwidgety 91 //91 -> 65
#define PATH getHomPath()

#define ICON ":/icons/icons/search.png"
#define INTERNETICON ":/icons/icons/workflow_openurl.png"
#define SETICON ":/icons/icons/setting.png"
#define QUITICON ":/icons/icons/quit.png"
#define SEARCHICON ":/icons/icons/google.png"
#define EXEICON ":/icons/icons/application-x-executable.png"

#define SEARCHURL "https://www.google.com/search?q="

#define CFPATH (std::string(PATH)+"/.config/Mutate")
#define FREQUENCEPATH (CFPATH+"/frequence")
#define CONFPATH (CFPATH+"/config.ini")
#define THEMEPATH (CFPATH+"/theme.ini")
#define URLPATH (CFPATH+"/url.history")
#define APPSEARCHPATH ("/usr/share/applications")
//#define APPSEARCHPATH2 ("/usr/share/app-install/desktop")
#define ICONSEARCHPATHS {\
std::string("/usr/share/icons"),\
std::string("/usr/share/app-install/icons"),\
PATH + "/.local/share/icons",\
}

#define MAXADDTOLISTSIZE 9
#define MAXSORTSIZE 50
#define MAXPRINTSIZE 9

#define MOVE CenterToScreen(this);

std::string getHomPath();
void CenterToScreen(QWidget* widget);
#endif // CONFIG_H
