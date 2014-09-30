#include <vector>
#include <QGraphicsDropShadowEffect>
#include <QPlainTextEdit>
#include <QDir>
#include <QDirIterator>
#include <QProcess>
#include <sstream>
#include <iostream>
#include <thread>
#include <functional>
#include <QApplication>
#include <QThread>
#include <QDesktopWidget>
#include <QClipboard>
#include <iterator>
#include "widget.h"
#include "ui_widget.h"
#include "returnbyscript.h"
#include "defaulsearch.h"
#include "listwidget.h"
#include "listitem.h"
#include "doublelistitem.h"
#include "config_parse.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    mutex_paint(new QMutex),
    mutex_thread(new QMutex)

{

    ui->setupUi(this);
    plainTextEdit = new PlainText(FREQUENCEPATH.c_str(), ui->groupBox);
    plainTextEdit->parent = this;
    plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
    QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
    plainTextEdit->setSizePolicy(sizePolicy1);
    plainTextEdit->setMinimumSize(QSize(550, 75));
    plainTextEdit->setMaximumSize(QSize(2048, 75));
    QFont font2;
    font2.setPointSize(40);
    plainTextEdit->setFont(font2);
    plainTextEdit->setFocusPolicy(Qt::StrongFocus);
    plainTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    plainTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->formLayout->setWidget(0, QFormLayout::SpanningRole, plainTextEdit);
    listWidget = new ListWidget(ui->groupBox);
    plainTextEdit->listWidget = listWidget;
    listWidget->setObjectName(QStringLiteral("listWidget"));
    QFont font1;
    font1.setPointSize(20);
    listWidget->setFont(font1);
    listWidget->setFocusPolicy(Qt::NoFocus);
    ui->formLayout->setWidget(1, QFormLayout::SpanningRole, listWidget);
    listWidget->setStyleSheet("QListWidget{border: 1px solid white}\
                               QListWidget::item{padding : 3px 3px 3px 3px}");
    //listWidget->setStyleSheet("QListWidget::item::selected:{background: #FFFFFF");
    listWidget->setIconSize(QSize(iconsize, iconsize));
    listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    listWidget->setMinimumHeight(1024);
    listWidget->hide();
    ui->groupBox->setStyleSheet("QGroupBox{background:white;border-radius: 9px;}");
    QGraphicsDropShadowEffect *wndShadow = new QGraphicsDropShadowEffect;
    wndShadow->setBlurRadius(9.0);
    wndShadow->setColor(QColor(0, 0, 0, 160));
    wndShadow->setOffset(3.0);
    ui->groupBox->setGraphicsEffect(wndShadow);
    plainTextEdit->setStyleSheet("QPlainTextEdit{border: 1px solid white}");
    this->setAttribute(Qt::WA_TranslucentBackground,true);
    this->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);
    plainTextEdit->setFocus();
    connect(plainTextEdit, &QPlainTextEdit::textChanged, this, &Widget::defaultsearch);
    connect(listWidget, &QListWidget::currentRowChanged, this, &Widget::setOne);
    connect(listWidget, &QListWidget::itemPressed, this, &Widget::enterCurItem);
    plainTextEdit->setFocus();
}
void Widget::setOne()
{
    if (listWidget->currentRow() == -1) listWidget->setCurrentRow(0);
}

void Widget::enterCurItem()
{
    plainTextEdit->enterCurrentRow();
}

void Widget::hotkeyPressed()
{
    if (this->isVisible())
    {
        this->plainTextEdit->setPlainText("");
        this->hide();
    }
    else {
        this->val.clear();
        this->paint_mutex();
        this->plainTextEdit->setPlainText("");
        MOVE;
        this->show();
    }
}

void Widget::OtherhotkeyPressed(std::string s, bool argument)
{
    if (this->isVisible())
    {
        this->plainTextEdit->setPlainText("");
        this->hide();
    }
    else {
        if (argument) {
            this->val.clear();
            this->defaultsearch();
            this->paint_mutex();
            QClipboard* clipboard = QGuiApplication::clipboard();
            auto searchText = clipboard->text(QClipboard::Selection);
            QTextCursor t(this->plainTextEdit->document());
            this->plainTextEdit->setPlainText(QString::fromStdString(s + ' ') + searchText);
            t.setPosition(s.size() + 1 + searchText.size());
            this->plainTextEdit->setTextCursor(t);
            MOVE;
            this->show();
            this->defaultsearch();
        }
        else {
            try {
                std::shared_ptr<ConfigParse> C(new ConfigParse(CONFPATH));
                QProcess *newProcess = new QProcess();
                newProcess->start(QString::fromStdString(C->getValue(s, "ScriptAddress")));
            }
            catch(...){}
        }
    }
}

void Widget::defaultsearch()
{
    WidgetThread *w = new WidgetThread(this);
    w->start();
    connect(w, SIGNAL(shouldPaint()), this, SLOT(paint_mutex()));
}

void Widget::paint_mutex()
{
    mutex_paint->lock();
    this->paint();
    mutex_paint->unlock();
}

size_t Widget::partition(returnByScript *a, size_t p, size_t q)
{
    size_t r = q;
    for (size_t i = p; i < q; i++)
    {
        if (this->plainTextEdit->fparse.getValue(a[i].text) <
            this->plainTextEdit->fparse.getValue(a[r].text)) {
            std::swap(a[i--], a[--q]);
        }
    }
    std::swap(a[q], a[r]);
    return q;
}

void Widget::quicksort(returnByScript *a, size_t n)
{
    if (n < 2) return;
    size_t m = partition(a, 0, n - 1);
    this->quicksort(a, m);
    this->quicksort(a + m + 1, n - m - 1);
}

void Widget::paint()
{
    listWidget->clear();
    int size = std::min(int(val.size()), MAXADDTOLISTSIZE);
    int printsize = std::min(int(val.size()), MAXPRINTSIZE);
    if (val.empty())
    {
        listWidget->hide();
        this->setMaximumHeight(printsize * rowsize + beginheight - 6);
        this->setMinimumHeight(printsize * rowsize + beginheight - 6);
        this->setGeometry(this->x(), this->y(), val.size() * rowsize + beginheight, this->width());
        return;
    }
    listWidget->show();
    listWidget->setMaximumHeight(rowsize * printsize);
    listWidget->setGeometry(listWidget->x(), listwidgety, listWidget->width(), rowsize * printsize);
    this->quicksort((&val[0]), std::min(MAXSORTSIZE, int(val.size())));
    this->setMaximumHeight(printsize * rowsize + beginheight);
    this->setMinimumHeight(printsize * rowsize + beginheight);
    this->setGeometry(this->x(), this->y(), printsize * rowsize + beginheight, this->width());

    for (int i = 0; i != size; i++)
    {
        QWidget* l;
        if (val[i].subtext == "") {
            if (i < MAXPRINTSIZE) {
                if (val[i].qicon == NULL) {
                    l = new ListItem(val[i].icon, val[i].text, std::string("Alt+") + std::to_string(i + 1));
                }
                else {
                    l = new ListItem(val[i].qicon, val[i].text, std::string("Alt+") + std::to_string(i + 1));
                }
            }
            else {
                if (val[i].qicon == NULL) {
                    l = new ListItem(val[i].icon, val[i].text, std::to_string(i + 1));
                }
                else {
                    l = new ListItem(val[i].qicon, val[i].text, std::to_string(i + 1));
                }
            }
            QListWidgetItem * item = new QListWidgetItem(listWidget);
            item->setSizeHint(QSize(l->width(), l->height()));
            listWidget->addItem(item);
            listWidget->setItemWidget(item, l);
        }
        else {
            if (i < MAXPRINTSIZE)
            {
                if (val[i].qicon == NULL) {
                    l = new DoubleListItem(val[i].icon, val[i].text, val[i].subtext, std::string("Alt+") + std::to_string(i + 1));
                }
                else {
                    l = new DoubleListItem(val[i].qicon, val[i].text, val[i].subtext, std::string("Alt+") + std::to_string(i + 1));
                }
            }
            else {
                if (val[i].qicon == NULL) {
                    l = new ListItem(val[i].icon, val[i].text, std::to_string(i + 1));
                }
                else {
                    l = new ListItem(val[i].qicon, val[i].text, std::to_string(i + 1));
                }
            }
            QListWidgetItem * item = new QListWidgetItem(listWidget);
            item->setSizeHint(QSize(l->width(), l->height()));
            listWidget->addItem(item);
            listWidget->setItemWidget(item, l);
        }
    }
    listWidget->setCurrentRow(0);
    listWidget->setGeometry(listWidget->x(), listwidgety, listWidget->width(), rowsize * printsize);
    MOVE;
}
#undef signals

extern "C" {
#include <gio/gio.h>
#include <gtk/gtk.h>
}
#include "gpixbuftoqicon.h"

void Widget::searchApp()
{
    auto apps = g_app_info_get_all();
    GtkIconTheme *pGtkIconTheme= gtk_icon_theme_get_default();
    GError* err = 0;

    while (apps->next != NULL)
    {
        try {

            std::string display(g_app_info_get_display_name((GAppInfo*)(apps->data)));
            std::string command(g_app_info_get_executable((GAppInfo*)(apps->data)));

            GIcon* icon = g_app_info_get_icon((GAppInfo*)(apps->data));

            auto pGtkIconInfo = gtk_icon_theme_lookup_by_gicon(pGtkIconTheme,icon,256,GTK_ICON_LOOKUP_USE_BUILTIN);
            auto giconinfo = gtk_icon_info_load_icon(pGtkIconInfo, &err);

            if (err == 0)
            {
                auto qicon = giconToQIcon(giconinfo);
                map.push_back({display, {command, qicon}});
            }
            else
            {
                map.push_back({display, {command, NULL}});
            }

            apps = apps->next;


        }
        catch (...){apps = apps->next;continue;}
    }
}

Widget::~Widget()
{
    delete ui;
}
