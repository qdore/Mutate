#include "setting.h"
#include "hotkey.h"
#include "ui_setting.h"
#include "config_parse.h"
#include <QString>
#include <QFileDialog>
#include <string>
#include <fstream>
#include <QMessageBox>



Setting::Setting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);
    try {
        ConfigParse cp(CONFPATH);
        auto sects = cp.getSections();
        for (unsigned int i = 0; i != sects.size(); i++)
        {

            int row_count = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row_count);
            QTableWidgetItem *name = new QTableWidgetItem();
            QTableWidgetItem *icon = new QTableWidgetItem();
            QTableWidgetItem *hotkey = new QTableWidgetItem();
            QTableWidgetItem *keyword = new QTableWidgetItem();
            QTableWidgetItem *argument = new QTableWidgetItem();
            name->setIcon(QIcon(QString::fromStdString(cp.getValue(sects[i], "IconAddress"))));
            name->setText(QString::fromStdString(cp.getValue(sects[i], "ScriptAddress")));
            icon->setText(QString::fromStdString(cp.getValue(sects[i], "IconAddress")));
            hotkey->setText(QString::fromStdString(cp.getValue(sects[i], "HotKey")));
            keyword->setText(QString::fromStdString(sects[i]));
            argument->setText(QString::fromStdString(cp.getValue(sects[i], "Argument")));
            if (sects[i] == "default")
            {
                ui->Height->setText(QString::fromStdString(cp.getValue(sects[i], "Height")));
            }
            ui->tableWidget->setItem(row_count, 0, name);
            ui->tableWidget->setItem(row_count, 1, icon);
            ui->tableWidget->setItem(row_count, 2, hotkey);
            ui->tableWidget->setItem(row_count, 3, keyword);
            ui->tableWidget->setItem(row_count, 4, argument);
        }
    }
    catch (ConfigParseEx& e)
    {
        QMessageBox* x = new QMessageBox();
        x->setText(QString::fromStdString(e.msg));
        x->exec();
    }

    std::ifstream themeFile((THEMEPATH).c_str());
    std::string themeName;
    std::getline(themeFile, themeName);
    if (themeName == "Classic")
    {
        ui->comboBox->setCurrentIndex(0);
    }
    else
    {
        ui->comboBox->setCurrentIndex(1);
    }

    connect(ui->openfile, &QToolButton::pressed, this, &Setting::openScript);
    connect(ui->openfile_2, &QToolButton::pressed, this, &Setting::openIcon);
    connect(ui->hotkey_2, &QToolButton::pressed, this, &Setting::pressHotkey);
    connect(ui->add, &QPushButton::pressed, this, &Setting::addItem);
    connect(ui->delete_2, &QPushButton::pressed, this, &Setting::deleteItem);
    connect(ui->save, &QPushButton::pressed, this, &Setting::saveItems);
    connect(ui->tableWidget, &QTableWidget::pressed, this, &Setting::changeItem);
    connect(ui->modify, &QPushButton::pressed, this, &Setting::modifyItem);
}
void Setting::modifyItem()
{
    QTableWidgetItem *name = new QTableWidgetItem();
    QTableWidgetItem *icon = new QTableWidgetItem();
    QTableWidgetItem *hotkey = new QTableWidgetItem();
    QTableWidgetItem *keyword = new QTableWidgetItem();
    QTableWidgetItem *argument = new QTableWidgetItem();
    name->setIcon(QIcon(ui->iconaddress->text()));
    name->setText(ui->fileaddress->text());
    icon->setText(ui->iconaddress->text());
    hotkey->setText(ui->hotkey->text());
    keyword->setText(ui->keyword->text());
    if (ui->checkBox->checkState() == Qt::Checked)
    {
        argument->setText(QObject::tr("need"));
    }
    else {
        argument->setText(QObject::tr("none"));
    }
    ui->tableWidget->setItem(ui->tableWidget->currentRow(), 0, name);
    ui->tableWidget->setItem(ui->tableWidget->currentRow(), 1, icon);
    ui->tableWidget->setItem(ui->tableWidget->currentRow(), 2, hotkey);
    ui->tableWidget->setItem(ui->tableWidget->currentRow(), 3, keyword);
    ui->tableWidget->setItem(ui->tableWidget->currentRow(), 4, argument);
}

void Setting::changeItem()
{
    ui->iconaddress->setText(ui->tableWidget->item(ui->tableWidget->currentRow(), 1)->text());
    ui->fileaddress->setText(ui->tableWidget->item(ui->tableWidget->currentRow(), 0)->text());
    ui->hotkey->setText(ui->tableWidget->item(ui->tableWidget->currentRow(), 2)->text());
    ui->keyword->setText(ui->tableWidget->item(ui->tableWidget->currentRow(), 3)->text());
    if (ui->tableWidget->item(ui->tableWidget->currentRow(), 3)->text() == "need")
    {
        ui->checkBox->setChecked(true);
    }
    else
    {
        ui->checkBox->setChecked(false);
    }
}

void Setting::saveItems()
{
    if (ui->tableWidget->rowCount() == 0)
    {
        QMessageBox* x = new QMessageBox();
        x->setText(QString::fromStdString("The table is Null!"));
        x->exec();
        return;
    }
    std::ofstream out((CONFPATH).c_str());
    for (int i = 0; i != ui->tableWidget->rowCount(); i++)
    {
        out << '[' << ui->tableWidget->item(i, 3)->text().toStdString() << ']' << std::endl;
        out << "ScriptAddress" << '=' << ui->tableWidget->item(i, 0)->text().toStdString() << std::endl;
        out << "IconAddress" << '=' << ui->tableWidget->item(i, 1)->text().toStdString() << std::endl;
        out << "HotKey" << '=' << ui->tableWidget->item(i, 2)->text().toStdString() << std::endl;
        out << "Argument" << '=' << ui->tableWidget->item(i, 4)->text().toStdString() << std::endl;
        if (ui->tableWidget->item(i, 3)->text().toStdString() == "default")
        {
            out << "Height" << '=' << ui->Height->text().toStdString() << std::endl;
        }
    }
    out.close();

    std::ofstream out_theme((THEMEPATH).c_str());
    QString theme = ui->comboBox->currentText();
    std::string themeStr = theme.toStdString();
    out_theme << themeStr;
    out_theme.close();

    QApplication::quit();
    QProcess::startDetached(QApplication::applicationFilePath());
}

void Setting::deleteItem()
{
    if (!ui->tableWidget->selectedItems().empty()) {
        ui->tableWidget->removeRow(ui->tableWidget->selectedItems()[0]->row());
    }
}
void Setting::addItem()
{
    int row_count = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row_count);
    QTableWidgetItem *name = new QTableWidgetItem();
    QTableWidgetItem *icon = new QTableWidgetItem();
    QTableWidgetItem *hotkey = new QTableWidgetItem();
    QTableWidgetItem *keyword = new QTableWidgetItem();
    QTableWidgetItem *argument = new QTableWidgetItem();
    name->setIcon(QIcon(ui->iconaddress->text()));
    name->setText(ui->fileaddress->text());
    icon->setText(ui->iconaddress->text());
    hotkey->setText(ui->hotkey->text());
    keyword->setText(ui->keyword->text());
    if (ui->checkBox->checkState() == Qt::Checked)
    {
        argument->setText(QObject::tr("need"));
    }
    else {
        argument->setText(QObject::tr("none"));
    }
    ui->tableWidget->setItem(row_count, 0, name);
    ui->tableWidget->setItem(row_count, 1, icon);
    ui->tableWidget->setItem(row_count, 2, hotkey);
    ui->tableWidget->setItem(row_count, 3, keyword);
    ui->tableWidget->setItem(row_count, 4, argument);
    ui->iconaddress->setText("");
    ui->fileaddress->setText("");
    ui->hotkey->setText("");
    ui->keyword->setText("");
    ui->checkBox->setChecked(false);
}
void Setting::openScript()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("open file"), " ",  tr("Allfile(*.*)"));
    ui->fileaddress->setText(fileName);
}
void Setting::openIcon()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("open file"), " ",  tr("Allfile(*.*)"));
    ui->iconaddress->setText(fileName);
}
void Setting::pressHotkey()
{
    hotkey *h = new hotkey;
    h->s = this->ui->hotkey;
    h->show();
}
Setting::~Setting()
{
    delete ui;
}
