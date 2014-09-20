#include "listwidget.h"
#include <QMouseEvent>
#include <iostream>

ListWidget::ListWidget(QWidget *parent) :
    QListWidget(parent)
{
    this->setMouseTracking(true);
}

void ListWidget::mouseMoveEvent(QMouseEvent* event)
{
    int row = indexAt(event->pos()).row();
    this->setCurrentRow(row);
}

