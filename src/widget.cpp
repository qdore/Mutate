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
#include <fstream>
#include "widget.h"
#include "ui_widget.h"
#include "returnbyscript.h"
#include "defaulsearch.h"
#include "listwidget.h"
#include "listitem.h"
#include "doublelistitem.h"
#include "config_parse.h"
#include "theme.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    mutex_paint(new QMutex),
    mutex_thread(new QMutex)

{

    ui->setupUi(this);

    setUpTheme();

    plainTextEdit = new PlainText(FREQUENCEPATH.c_str(), ui->groupBox);
    plainTextEdit->parent = this;
    plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

    QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());

    plainTextEdit->setSizePolicy(sizePolicy1);
    plainTextEdit->setMinimumSize(theme->dimensions());
    plainTextEdit->setMaximumSize(QSize(2048, theme->dimensions().height())); //custom theme dimensions

    QFont font2;
    font2.setPointSize(theme->fontSize()); //custom theme font size

    plainTextEdit->setFont(font2);
    plainTextEdit->setFocusPolicy(Qt::StrongFocus);
    plainTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    plainTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
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

    listWidget->setStyleSheet(theme->listWidgetStylesheet()); //custom theme list widget
    listWidget->setIconSize(QSize(iconsize, iconsize));
    listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    listWidget->setMinimumHeight(1024);
    listWidget->hide();

    ui->groupBox->setStyleSheet(theme->groupBoxStylesheet()); //custom theme group box

    QGraphicsDropShadowEffect *wndShadow = new QGraphicsDropShadowEffect;
    wndShadow->setBlurRadius(theme->blurRadius());
    wndShadow->setColor(theme->shadowColor());
    wndShadow->setOffset(theme->shadowOffset()); //custom theme shadow
    ui->groupBox->setGraphicsEffect(wndShadow);

    plainTextEdit->setStyleSheet(theme->plainTextEditStylesheet()); //custom theme text edit

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

/**
 * @brief Widget::setUpTheme
 * Function reads from file "theme.ini" the theme and applies it.
 * Two themes are supported: classic and dark.
 */
void Widget::setUpTheme()
{
    std::ifstream themeFile(THEMEPATH);
    std::string themeName;

    if (!themeFile.is_open())
    {
        themeName = "Classic";
    }
    else
    {
        std::getline(themeFile, themeName);
        themeFile.close();
    }

    theme = new Theme();

    int globalBeginHeight;
    int globalListWidgetY;
    QSize dimensions;
    QString groupBoxStylesheet;
    QString plainTextEditStylesheet;
    QString listWidgetStylesheet;
    int fontSize;
    qreal blurRadius;
    QColor shadowColor;
    qreal shadowOffset;

    if(themeName == "Classic")
    {

        globalBeginHeight = 125;
        globalListWidgetY = 91;
        dimensions = QSize(550, 75);
        groupBoxStylesheet = "QGroupBox{background:white;border-radius: 9px;}";
        plainTextEditStylesheet = "QPlainTextEdit{border: 1px solid white}";
        listWidgetStylesheet = "QListWidget{border: 1px solid white} QListWidget::item{padding : 3px 3px 3px 3px}";
        fontSize = 40;
        blurRadius = 9.0;
        shadowColor = QColor(0, 0, 0, 160);
        shadowOffset = 3.0;
    }
    else
    {
        globalBeginHeight = 94;
        globalListWidgetY = 65;
        dimensions = QSize(550, 50);
        groupBoxStylesheet = "QGroupBox{background:#444444;border-radius: 9px; padding: -3px -3px -3px -3px;}";
        plainTextEditStylesheet = "QPlainTextEdit{background:#3a3a3a; border: 1px solid #3a3a3a; color: #AAAAAA}";
        listWidgetStylesheet = "QListWidget { background: #444444; border: 1px solid #444444}\
                                        QListWidget::item { background: #444444; padding: 0px 0px 0px 3px;}\
                                        QListWidget::item:selected { background: #525252; border: 1px solid #AAAAAA; border-radius: 2px;}\
                                        QLabel {color: #AAAAAA;}";
        fontSize = 30;
        blurRadius = 10.0;
        shadowColor = QColor(0, 0, 0, 200);
        shadowOffset = 0.0;
    }

    theme->setBeginHeight(globalBeginHeight);
    theme->setListWidgetY(globalListWidgetY);
    theme->setDimensions(dimensions);
    theme->setGroupBoxStylesheet(groupBoxStylesheet);
    theme->setPlainTextEditStylesheet(plainTextEditStylesheet);
    theme->setListWidgetStylesheet(listWidgetStylesheet);
    theme->setFontSize(fontSize);
    theme->setBlurRadius(blurRadius);
    theme->setShadowColor(shadowColor);
    theme->setShadowOffset(shadowOffset);
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
        this->setMaximumHeight(printsize * rowsize + theme->beginHeight() - 6); //custom theme begin height
        this->setMinimumHeight(printsize * rowsize + theme->beginHeight() - 6);
        this->setGeometry(this->x(), this->y(), val.size() * rowsize + theme->beginHeight(), this->width());
        return;
    }
    listWidget->show();
    listWidget->setMaximumHeight(rowsize * printsize);
    listWidget->setGeometry(listWidget->x(), theme->listWidgetY(), listWidget->width(), rowsize * printsize);
    this->quicksort((&val[0]), std::min(MAXSORTSIZE, int(val.size())));
    this->setMaximumHeight(printsize * rowsize + theme->beginHeight());
    this->setMinimumHeight(printsize * rowsize + theme->beginHeight());
    this->setGeometry(this->x(), this->y(), printsize * rowsize + theme->beginHeight(), this->width());

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
    listWidget->setGeometry(listWidget->x(), theme->listWidgetY(), listWidget->width(), rowsize * printsize);
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

void Widget::setApp(SingleApplication *app)
{
    plainTextEdit->setApp(app);
}
