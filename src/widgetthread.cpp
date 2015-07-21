#include "widgetthread.h"
#include "widget.h"
#include "defaulsearch.h"
#include <string>
#include <QCoreApplication>

WidgetThread::WidgetThread(QWidget* w, QWidget*):w(w)
{}
void WidgetThread::run()
{
    std::string text = (static_cast<Widget*>(w))->plainTextEdit->toPlainText().toStdString();
    defaulSearch search(text);
    auto tmp = search.getReturnVec((static_cast<Widget*>(w))->map);
    static_cast<Widget*>(w)->mutex_thread->lock();
    if (text == (static_cast<Widget*>(w))->plainTextEdit->toPlainText().toStdString())
    {
        (static_cast<Widget*>(w))->val = tmp;
        (static_cast<Widget*>(w))->plainTextEdit->val = &((static_cast<Widget*>(w))->val);
        emit shouldPaint();
    }
    static_cast<Widget*>(w)->mutex_thread->unlock();
}

SearchApp::SearchApp(QWidget* w, QWidget*):w(w)
{}

void SearchApp::run()
{
    (static_cast<Widget*>(w))->searchApp();
}
