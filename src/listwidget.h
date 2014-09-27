#ifndef LISTWIDGET_H
#define LISTWIDGET_H
#include <QListWidget>
#include <QWidget>
#include "plaintext.h"

class ListWidget : public QListWidget
{
    Q_OBJECT
public:
    explicit ListWidget(QWidget *parent = 0);
    void mouseMoveEvent(QMouseEvent* event);
};

#endif // LISTWIDGET_H
