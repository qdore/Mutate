#include "returnbyscript.h"
#include <QString>

returnByScript::returnByScript(std::string icon, std::string text, std::string command, std::string subtext, QIcon* qicon):
    icon(icon),
    text(text),
    subtext(subtext),
    command(command),
    qicon(qicon)
{}
bool returnByScript::operator==(const returnByScript& b)
{
    return this->text == b.text;
}
