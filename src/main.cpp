#include <qxtglobalshortcut/qxtglobalshortcut.h>
#include <QApplication>
#include <QDesktopWidget>
#include <QObject>
#include <vector>
#include <QMessageBox>
#include <QProcess>
#include <iostream>
#include <memory>
#include <QIcon>
#include <QDir>
#include "widget.h"
#include "hotkey.h"
#include "returnbyscript.h"
#include "setting.h"
#include "singleapplication.h"
#include "config_parse.h"
#include "config.h"

using namespace std;

int main(int argc, char *argv[])
{
    qRegisterMetaType<QItemSelection>("QItemSelection");
    SingleApplication a(argc, argv, "WEI.QIANG");
    QDir *config = new QDir;
    if (!config->exists(QString::fromStdString(CFPATH))) config->mkdir(QString::fromStdString(CFPATH));
    delete config;
    if (a.isRunning())
    {
        QMessageBox* x = new QMessageBox();
        x->setText(QObject::tr("One Application May be running!Please try again~"));
        x->exec();
        return -1;
    }
    a.setWindowIcon(QIcon(SEARCHICON));
    a.setQuitOnLastWindowClosed(false);
    Widget * w = new Widget;
    try{
        shared_ptr<ConfigParse> cp(new ConfigParse(CONFPATH));
        for (const string& keyword: cp->getSections())
        {
            if (keyword == "default")
            {
                string default_key = cp->getValue(keyword, "HotKey");
                QxtGlobalShortcut *shortcut = new QxtGlobalShortcut(QKeySequence(default_key.c_str()), w);
                QObject::connect(shortcut, &QxtGlobalShortcut::activated, w, &Widget::hotkeyPressed);
            }
            else {
                string default_key = cp->getValue(keyword, "HotKey");
                if (!default_key.empty()) {
                    QxtGlobalShortcut *shortcut;
                    if (cp->getValue(keyword, "Argument") == "need")
                    {
                        shortcut = new QxtGlobalShortcut(QKeySequence(default_key.c_str()),  w, keyword, true);
                    }
                    else
                    {
                        shortcut = new QxtGlobalShortcut(QKeySequence(default_key.c_str()),  w, keyword, false);
                    }
                    QObject::connect(shortcut, SIGNAL(activated(std::string, bool)), w, SLOT(OtherhotkeyPressed(std::string, bool)));
                }
            }
        }
    }
    catch(...)
    {
        QxtGlobalShortcut *shortcut = new QxtGlobalShortcut(QKeySequence("Alt+d"), w);
        QObject::connect(shortcut, &QxtGlobalShortcut::activated, w, &Widget::hotkeyPressed);
    }
    std::shared_ptr<SearchApp> s(new SearchApp(w));
    s->start();
    w->hotkeyPressed();
    return a.exec();
}
