/********************************************************************************
** Form generated from reading UI file 'hotkey.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOTKEY_H
#define UI_HOTKEY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_hotkey
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *hotkey)
    {
        if (hotkey->objectName().isEmpty())
            hotkey->setObjectName(QStringLiteral("hotkey"));
        hotkey->resize(122, 64);
        gridLayout = new QGridLayout(hotkey);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(hotkey);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(13);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(hotkey);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);


        retranslateUi(hotkey);

        QMetaObject::connectSlotsByName(hotkey);
    } // setupUi

    void retranslateUi(QWidget *hotkey)
    {
        hotkey->setWindowTitle(QApplication::translate("hotkey", "Form", 0));
        label->setText(QApplication::translate("hotkey", "< press key>", 0));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class hotkey: public Ui_hotkey {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOTKEY_H
