#ifndef RETURNBYSCRIPT_H
#define RETURNBYSCRIPT_H
#include <string>
#include <QIcon>

class returnByScript
{
public:
    std::string icon;
    std::string text;
    std::string subtext;
    std::string command;
    QIcon* qicon;
public:
    returnByScript(std::string icon, std::string text,  std::string command, std::string subtext = "", QIcon* qicon = NULL);
    bool operator ==(const returnByScript& b);
};

#endif // RETURNBYSCRIPT_H
