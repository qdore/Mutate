#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <vector>
#include <QListWidget>
#include <QMutex>
#include <string>
#include <map>
#include "widgetthread.h"
#include "plaintext.h"
#include "returnbyscript.h"
#include "config.h"
#include "singleapplication.h"

typedef std::vector<std::pair<std::string, std::pair<std::string, QIcon*>>> pair;
typedef std::pair<std::string, std::pair<std::string, QIcon*>> qpair;
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    friend class WidgetThread;
public slots:
    void paint_mutex();
    void OtherhotkeyPressed(std::string, bool);
public:
    explicit Widget(QWidget *parent = 0);
    void defaultsearch();
    void searchApp();
    std::vector<returnByScript> val;
    void hotkeyPressed();
    void setOne();
    void enterCurItem();
    float Height;
    ~Widget();
    void setApp(SingleApplication *app);

private:
    void paint();
    QMutex* mutex_paint;
    QMutex* mutex_thread;
    void quicksort(returnByScript* a, size_t n);
    size_t partition(returnByScript* a, size_t p, size_t q);
    pair map;
    Ui::Widget *ui;
    PlainText *plainTextEdit;
    QListWidget *listWidget;
};
#endif // WIDGET_H
