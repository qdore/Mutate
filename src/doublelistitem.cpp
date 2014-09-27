#include "doublelistitem.h"
#include "ui_doublelistitem.h"
#include "config.h"
#include <QStringList>
#include <QString>

DoubleListItem::DoubleListItem(const string& icon, const string& text, const string& subtext, const string& cmd, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DoubleListItem)
{
    ui->setupUi(this);
    ui->subtext->setStyleSheet("QLabel{color: rgb(100, 100, 100)}");
    ui->cmd->setStyleSheet("QLabel{color: rgb(100, 100, 100)}");
    QFontMetrics fm(QFont(ui->text->font()));
    ui->text->setText(fm.elidedText(QString::fromStdString(text), Qt::ElideRight, ui->text->width()));
    QFontMetrics subfm(QFont(ui->subtext->font()));
    ui->subtext->setText(subfm.elidedText(QString::fromStdString(subtext), Qt::ElideRight, ui->subtext->width()));
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

DoubleListItem::DoubleListItem(const QIcon* icon, const string& text, const string& subtext, const string& cmd, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DoubleListItem)
{
    ui->setupUi(this);
    ui->subtext->setStyleSheet("QLabel{color: rgb(100, 100, 100)}");
    ui->cmd->setStyleSheet("QLabel{color: rgb(100, 100, 100)}");
    QFontMetrics fm(QFont(ui->text->font()));
    ui->text->setText(fm.elidedText(QString::fromStdString(text), Qt::ElideRight, ui->text->width()));
    QFontMetrics subfm(QFont(ui->subtext->font()));
    ui->subtext->setText(subfm.elidedText(QString::fromStdString(subtext), Qt::ElideRight, ui->subtext->width()));
    ui->cmd->setText(QString::fromStdString(cmd));
    QIcon tmp = *icon;
    QStringList sl;
    if (tmp.isNull())
    {
        tmp = QIcon(QString::fromStdString(EXEICON));
    }
    QPixmap p = tmp.pixmap(QSize(iconsize, iconsize));
    ui->icon->setPixmap(p);
}


DoubleListItem::~DoubleListItem()
{
    delete ui;
}
