#ifndef LISTITEM_H
#define LISTITEM_H

#include <QWidget>
#include <string>

using std::string;

namespace Ui {
class ListItem;
}

class ListItem : public QWidget
{
    Q_OBJECT

public:
    explicit ListItem(const string& icon, const string& text, const string& cmd, QWidget *parent = 0);
    explicit ListItem(const QIcon* icon, const string& text, const string& cmd, QWidget *parent = 0);

    ~ListItem();

private:
    Ui::ListItem *ui;
};

#endif // LISTITEM_H
