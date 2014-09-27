#include "listitem.h"
#include "ui_listitem.h"
#include "config.h"
#include <string>
#include <QString>
#include <QIcon>
#include <QFont>
#include <QFontMetrics>
#include <QPixmap>

ListItem::ListItem(const string& icon, const string& text, const string& cmd, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListItem)
{
    ui->setupUi(this);
    ui->cmd->setStyleSheet("QLabel{color: rgb(100, 100, 100)}");
    QFontMetrics fm(QFont(ui->text->font()));
    ui->text->setText(fm.elidedText(QString::fromStdString(text), Qt::ElideRight, ui->text->width()));
    ui->cmd->setText(QString::fromStdString(cmd));
    QIcon tmp;
    if (icon.find('/') == std::string::npos)
    {
        tmp = QIcon::fromTheme(QString::fromStdString(icon));
    }
    else
    {
        tmp = QIcon(QString::fromStdString(icon));
    }
    if (tmp.isNull())
    {
        tmp = QIcon(QString::fromStdString(EXEICON));
    }
    QPixmap p = tmp.pixmap(QSize(iconsize, iconsize));
    ui->icon->setPixmap(p);
}

ListItem::ListItem(const QIcon* icon, const string& text, const string& cmd, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListItem)
{
    ui->setupUi(this);
    ui->cmd->setStyleSheet("QLabel{color: rgb(100, 100, 100)}");
    QFontMetrics fm(QFont(ui->text->font()));
    ui->text->setText(fm.elidedText(QString::fromStdString(text), Qt::ElideRight, ui->text->width()));
    ui->cmd->setText(QString::fromStdString(cmd));
    QIcon tmp = *icon;
    if (tmp.isNull())
    {
        tmp = QIcon(QString::fromStdString(EXEICON));
    }
    QPixmap p = tmp.pixmap(QSize(iconsize, iconsize));
    ui->icon->setPixmap(p);
}

ListItem::~ListItem()
{
    delete ui;
}
