/********************************************************************************
** Form generated from reading UI file 'listitem.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTITEM_H
#define UI_LISTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListItem
{
public:
    QLabel *icon;
    QLabel *text;
    QLabel *cmd;

    void setupUi(QWidget *ListItem)
    {
        if (ListItem->objectName().isEmpty())
            ListItem->setObjectName(QStringLiteral("ListItem"));
        ListItem->resize(662, 51);
        icon = new QLabel(ListItem);
        icon->setObjectName(QStringLiteral("icon"));
        icon->setGeometry(QRect(0, 0, 51, 51));
        text = new QLabel(ListItem);
        text->setObjectName(QStringLiteral("text"));
        text->setGeometry(QRect(52, -3, 551, 51));
        QFont font;
        font.setPointSize(18);
        text->setFont(font);
        cmd = new QLabel(ListItem);
        cmd->setObjectName(QStringLiteral("cmd"));
        cmd->setGeometry(QRect(607, -2, 41, 51));
        QFont font1;
        font1.setPointSize(10);
        cmd->setFont(font1);
        cmd->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        retranslateUi(ListItem);

        QMetaObject::connectSlotsByName(ListItem);
    } // setupUi

    void retranslateUi(QWidget *ListItem)
    {
        ListItem->setWindowTitle(QApplication::translate("ListItem", "Form", 0));
        icon->setText(QString());
        text->setText(QApplication::translate("ListItem", "TextLabel", 0));
        cmd->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ListItem: public Ui_ListItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTITEM_H
