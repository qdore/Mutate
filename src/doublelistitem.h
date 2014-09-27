#ifndef DOUBLELISTITEM_H
#define DOUBLELISTITEM_H

#include <QWidget>
#include <string>

using std::string;

namespace Ui {
class DoubleListItem;
}

class DoubleListItem : public QWidget
{
    Q_OBJECT

public:
    explicit DoubleListItem(const string& icon, const string& text, const string& subtext, const string& cmd, QWidget *parent = 0);
    explicit DoubleListItem(const QIcon* icon, const string& text, const string& subtext, const string& cmd, QWidget *parent = 0);
    ~DoubleListItem();

private:
    Ui::DoubleListItem *ui;
};

#endif // DOUBLELISTITEM_H
