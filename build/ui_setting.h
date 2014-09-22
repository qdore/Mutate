/********************************************************************************
** Form generated from reading UI file 'setting.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_H
#define UI_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Setting
{
public:
    QGridLayout *gridLayout;
    QPushButton *save;
    QPushButton *delete_2;
    QTableWidget *tableWidget;
    QToolButton *openfile;
    QCheckBox *checkBox;
    QLabel *namel_2;
    QLineEdit *fileaddress;
    QLabel *namel_3;
    QLabel *namel;
    QLineEdit *hotkey;
    QToolButton *hotkey_2;
    QLabel *namel_4;
    QLineEdit *iconaddress;
    QToolButton *openfile_2;
    QLineEdit *keyword;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *add;
    QPushButton *modify;

    void setupUi(QWidget *Setting)
    {
        if (Setting->objectName().isEmpty())
            Setting->setObjectName(QStringLiteral("Setting"));
        Setting->resize(906, 313);
        Setting->setMaximumSize(QSize(100000, 100000));
        gridLayout = new QGridLayout(Setting);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        save = new QPushButton(Setting);
        save->setObjectName(QStringLiteral("save"));
        save->setMaximumSize(QSize(100000, 100000));

        gridLayout->addWidget(save, 13, 3, 1, 1);

        delete_2 = new QPushButton(Setting);
        delete_2->setObjectName(QStringLiteral("delete_2"));
        delete_2->setMaximumSize(QSize(100000, 100000));

        gridLayout->addWidget(delete_2, 10, 4, 1, 2);

        tableWidget = new QTableWidget(Setting);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setMaximumSize(QSize(100000, 100000));

        gridLayout->addWidget(tableWidget, 0, 0, 14, 1);

        openfile = new QToolButton(Setting);
        openfile->setObjectName(QStringLiteral("openfile"));

        gridLayout->addWidget(openfile, 0, 5, 1, 1);

        checkBox = new QCheckBox(Setting);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout->addWidget(checkBox, 4, 4, 1, 1);

        namel_2 = new QLabel(Setting);
        namel_2->setObjectName(QStringLiteral("namel_2"));

        gridLayout->addWidget(namel_2, 1, 3, 1, 1);

        fileaddress = new QLineEdit(Setting);
        fileaddress->setObjectName(QStringLiteral("fileaddress"));
        fileaddress->setMaximumSize(QSize(150, 100000));

        gridLayout->addWidget(fileaddress, 0, 4, 1, 1);

        namel_3 = new QLabel(Setting);
        namel_3->setObjectName(QStringLiteral("namel_3"));

        gridLayout->addWidget(namel_3, 2, 3, 1, 1);

        namel = new QLabel(Setting);
        namel->setObjectName(QStringLiteral("namel"));

        gridLayout->addWidget(namel, 0, 3, 1, 1);

        hotkey = new QLineEdit(Setting);
        hotkey->setObjectName(QStringLiteral("hotkey"));
        hotkey->setMaximumSize(QSize(150, 100000));

        gridLayout->addWidget(hotkey, 2, 4, 1, 1);

        hotkey_2 = new QToolButton(Setting);
        hotkey_2->setObjectName(QStringLiteral("hotkey_2"));

        gridLayout->addWidget(hotkey_2, 2, 5, 1, 1);

        namel_4 = new QLabel(Setting);
        namel_4->setObjectName(QStringLiteral("namel_4"));

        gridLayout->addWidget(namel_4, 3, 3, 1, 1);

        iconaddress = new QLineEdit(Setting);
        iconaddress->setObjectName(QStringLiteral("iconaddress"));
        iconaddress->setMaximumSize(QSize(150, 100000));

        gridLayout->addWidget(iconaddress, 1, 4, 1, 1);

        openfile_2 = new QToolButton(Setting);
        openfile_2->setObjectName(QStringLiteral("openfile_2"));

        gridLayout->addWidget(openfile_2, 1, 5, 1, 1);

        keyword = new QLineEdit(Setting);
        keyword->setObjectName(QStringLiteral("keyword"));
        keyword->setMaximumSize(QSize(150, 100000));

        gridLayout->addWidget(keyword, 3, 4, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 9, 3, 1, 3);

        add = new QPushButton(Setting);
        add->setObjectName(QStringLiteral("add"));
        add->setMaximumSize(QSize(100000, 100000));

        gridLayout->addWidget(add, 10, 3, 1, 1);

        modify = new QPushButton(Setting);
        modify->setObjectName(QStringLiteral("modify"));
        modify->setMaximumSize(QSize(100000, 100000));

        gridLayout->addWidget(modify, 13, 4, 1, 2);


        retranslateUi(Setting);

        QMetaObject::connectSlotsByName(Setting);
    } // setupUi

    void retranslateUi(QWidget *Setting)
    {
        Setting->setWindowTitle(QApplication::translate("Setting", "Form", 0));
        save->setText(QApplication::translate("Setting", "save", 0));
        delete_2->setText(QApplication::translate("Setting", "delete item", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Setting", "script address", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Setting", "icon address", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Setting", "hotkey", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Setting", "keyword", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Setting", "Argument", 0));
        openfile->setText(QApplication::translate("Setting", "...", 0));
        checkBox->setText(QApplication::translate("Setting", "Argument Required", 0));
        namel_2->setText(QApplication::translate("Setting", "Icon address:", 0));
        namel_3->setText(QApplication::translate("Setting", "hotkey:", 0));
        namel->setText(QApplication::translate("Setting", "Script address:", 0));
        hotkey_2->setText(QApplication::translate("Setting", "...", 0));
        namel_4->setText(QApplication::translate("Setting", "keyword", 0));
        iconaddress->setText(QString());
        openfile_2->setText(QApplication::translate("Setting", "...", 0));
        keyword->setText(QString());
        add->setText(QApplication::translate("Setting", "add item", 0));
        modify->setText(QApplication::translate("Setting", "Modify item", 0));
    } // retranslateUi

};

namespace Ui {
    class Setting: public Ui_Setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_H
