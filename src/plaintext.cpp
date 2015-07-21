#include "plaintext.h"
#include "setting.h"
#include "config_parse.h"
#include <iostream>
#include <QTextEdit>
#include <QProcess>
#include <QClipboard>
#include <fstream>
#include <memory>

using namespace std;

PlainText::PlainText(const char *file, QWidget *parent):
    QPlainTextEdit(parent),
    fparse(file)
{}
void PlainText::enterCurrentRow()
{
    enterListWidget(listWidget->currentRow());
}


void PlainText::enterListWidget(int row)
{
    if (row < listWidget->count() && row >= 0)
    {
        if ((*val)[row].icon == INTERNETICON)
        try
        {
            std::shared_ptr<ConfigParse> C(new ConfigParse(URLPATH));
            auto tmp = C->getSections();
            if (std::find(tmp.begin(), tmp.end(), (*val)[row].text) == tmp.end()){
                std::ofstream out(URLPATH, std::ios::app);
                out << '[' << (*val)[row].text << ']' << std::endl;
            }
        }catch(...)
        {
            std::ofstream out(URLPATH, std::ios::app);
            out << '[' << (*val)[row].text << ']' << std::endl;
        }
        if ((*val)[row].command == "copy")
        {
            QClipboard* clipboard = QGuiApplication::clipboard();
            this->parent->hide();
            clipboard->setText(QString::fromStdString((*val)[row].text), QClipboard::Clipboard);
            clipboard->setText(QString::fromStdString((*val)[row].text), QClipboard::Selection);
            return;
        }
        if ((*val)[row].command == "setting")
        {
            Setting * s = new Setting;
            s->show();
            return;
        }
        if ((*val)[row].command == "complete")
        {
            int pos = (*val)[row].text.size();
            this->setPlainText(QString::fromStdString((*val)[row].text + ' '));
            QTextCursor t(this->document());
            t.setPosition(pos + 1);
            this->setTextCursor(t);
            return;
        }

        if ((*val)[row].command == "miss")
        {
            return;
        }

        if ((*val)[row].command == "quit")
        {
            (*aptr).quit();
            return;
        }

        this->parent->hide();
        if (!(*val)[row].command.empty())
        {
            QProcess::startDetached(QString::fromStdString((*val)[row].command));
            fparse.addValue((*val)[row].text, 1);
            fparse.storeValue();
        }
    }

}

void PlainText::keyPressEvent(QKeyEvent* event)
{
    Qt::KeyboardModifiers modifiers = event->modifiers();
    int uKey = event->key();
    Qt::Key key = static_cast<Qt::Key>(uKey);
    if(modifiers & Qt::AltModifier) {
        if (key >= Qt::Key_1 && key <= Qt::Key_1 + std::min(this->listWidget->count(), MAXPRINTSIZE) - 1)
        {
            this->enterListWidget(key - Qt::Key_1);
        }
        return;
    }
    if (key == 16777220 || key == Qt::Key_Enter)
    {
        enterListWidget(listWidget->currentRow());
        return;
    }
    if (listWidget->count() > 0)
    {
        if (key == Qt::Key_Up)
        {
            listWidget->setCurrentRow((listWidget->currentRow() + listWidget->count() - 1) % listWidget->count());
            return;
        }
        if (key == Qt::Key_Down)
        {
            listWidget->setCurrentRow((listWidget->currentRow() + 1) % listWidget->count());
            return;
        }
    }
    if (modifiers & Qt::MetaModifier) return;
    if (modifiers & Qt::ControlModifier)
    {
        if (key != Qt::Key_C && key != Qt::Key_V && key != Qt::Key_A && key != Qt::Key_X)
        {
            return;
        }
    }
    QPlainTextEdit::keyPressEvent(event);
}
void PlainText::focusOutEvent(QFocusEvent*)
{
    //this->parent->hide();
}

void PlainText::setApp(SingleApplication* app)
{
    aptr = app;
}
