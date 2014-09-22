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
public:
    returnByScript(std::string icon, std::string text,  std::string command, std::string subtext = "");
    bool operator ==(const returnByScript& b);
};

#endif // RETURNBYSCRIPT_H
