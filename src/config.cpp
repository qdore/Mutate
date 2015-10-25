//#include "config.h"
#include "widget.h"

std::string getHomPath()
{
    QStringList environment = QProcess::systemEnvironment();
    QString str;
    std::string tmp;
    foreach(str, environment)
    {
        if (str.startsWith("HOME="))
        {
            tmp = str.toStdString().substr(5, str.size());
            std::istringstream in(tmp);
            in >> tmp;
        }
    }
    return tmp;
}

void CenterToScreen(QWidget* widget)
{
    if (!widget)
        return;
    QDesktopWidget* m = QApplication::desktop();
    QRect desk_rect = m->screenGeometry(m->screenNumber(QCursor::pos()));
    int desk_x = desk_rect.width();
    int desk_y = desk_rect.height();
    int x = widget->width();
    widget->move(desk_x / 2 - x / 2 + desk_rect.left(), \
                (desk_y - beginheight - \
                    rowsize * (MAXPRINTSIZE - 1)) \
                   * ((Widget*)(widget))->Height);
}
