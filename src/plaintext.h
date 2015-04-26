#ifndef PLAINTEXT_H
#define PLAINTEXT_H
#include <QPlainTextEdit>
#include <QListWidget>
#include <QWidget>
#include "returnbyscript.h"
#include "frequenceparse.h"
#include "singleapplication.h"

class PlainText : public QPlainTextEdit
{
    Q_OBJECT
public:
    QWidget *parent;
    QListWidget *listWidget;
    FrequenceParse fparse;
    std::vector<returnByScript>* val;
    explicit PlainText(const char* file, QWidget *parent = 0);
    void keyPressEvent(QKeyEvent* event);
    void enterListWidget(int row);
    void focusOutEvent(QFocusEvent *event);
    void enterCurrentRow();
    void setApp(SingleApplication *app);
private:
    SingleApplication* aptr;
};

#endif // PLAINTEXT_H
