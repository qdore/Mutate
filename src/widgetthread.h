#ifndef WIDGETTHREAD_H
#define WIDGETTHREAD_H

#include <QThread>
#include <QWidget>

class WidgetThread: public QThread
{
    Q_OBJECT
private:
    QWidget *w;
signals:
    void shouldPaint();
public:
    WidgetThread(QWidget* w, QWidget *parent = 0);
    virtual void run();
};

class SearchApp: public QThread
{
    Q_OBJECT
private:
    QWidget *w;
public:
    SearchApp(QWidget* w, QWidget *parent = 0);
    virtual void run();
};

#endif // WIDGETTHREAD_H
