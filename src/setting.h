#ifndef SETTING_H
#define SETTING_H

#include <QWidget>
#include <QString>
#include <QProcess>
#include <QStringList>
#include <string>
#include <sstream>
#include "hotkey.h"
#include "config.h"


namespace Ui {
class Setting;
}

class Setting : public QWidget
{
    Q_OBJECT
public:
    explicit Setting(QWidget *parent = 0);
    ~Setting();
    void openScript();
    void openIcon();
    void pressHotkey();
    void addItem();
    void deleteItem();
    void modifyItem();
    void saveItems();
    void changeItem();

private:
    Ui::Setting *ui;
};

#endif // SETTING_H
