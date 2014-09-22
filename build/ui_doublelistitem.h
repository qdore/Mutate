/********************************************************************************
** Form generated from reading UI file 'doublelistitem.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOUBLELISTITEM_H
#define UI_DOUBLELISTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DoubleListItem
{
public:
    QLabel *text;
    QLabel *cmd;
    QLabel *icon;
    QLabel *subtext;

    void setupUi(QWidget *DoubleListItem)
    {
        if (DoubleListItem->objectName().isEmpty())
            DoubleListItem->setObjectName(QStringLiteral("DoubleListItem"));
        DoubleListItem->resize(662, 51);
        text = new QLabel(DoubleListItem);
        text->setObjectName(QStringLiteral("text"));
        text->setGeometry(QRect(52, -2, 551, 31));
        QFont font;
        font.setPointSize(18);
        text->setFont(font);
        cmd = new QLabel(DoubleListItem);
        cmd->setObjectName(QStringLiteral("cmd"));
        cmd->setGeometry(QRect(607, -2, 41, 51));
        QFont font1;
        font1.setPointSize(10);
        cmd->setFont(font1);
        cmd->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        icon = new QLabel(DoubleListItem);
        icon->setObjectName(QStringLiteral("icon"));
        icon->setGeometry(QRect(0, -2, 51, 53));
        subtext = new QLabel(DoubleListItem);
        subtext->setObjectName(QStringLiteral("subtext"));
        subtext->setGeometry(QRect(52, 25, 549, 23));
        QFont font2;
        font2.setPointSize(11);
        subtext->setFont(font2);

        retranslateUi(DoubleListItem);

        QMetaObject::connectSlotsByName(DoubleListItem);
    } // setupUi

    void retranslateUi(QWidget *DoubleListItem)
    {
        DoubleListItem->setWindowTitle(QApplication::translate("DoubleListItem", "Form", 0));
        text->setText(QApplication::translate("DoubleListItem", "TextLabel", 0));
        cmd->setText(QString());
        icon->setText(QString());
        subtext->setText(QApplication::translate("DoubleListItem", "TextLabelg", 0));
    } // retranslateUi

};

namespace Ui {
    class DoubleListItem: public Ui_DoubleListItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOUBLELISTITEM_H
