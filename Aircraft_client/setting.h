#ifndef SETTING_H
#define SETTING_H

#include<QWidget>
#include<QMouseEvent>
#include<QDebug>
#include<QDir>
#include<QJsonObject>
#include<QJsonDocument>


#include "tools.h"


namespace Ui {
class Setting;
}

class Setting : public QWidget
{
    Q_OBJECT

public:
    explicit Setting(QWidget *parent = nullptr);
    ~Setting();

    //最小化及关闭
    bool eventFilter(QObject *object, QEvent *e);
    bool try_saveSetting();

private:

    Ui::Setting *ui;

};

#endif // SETTING_H
