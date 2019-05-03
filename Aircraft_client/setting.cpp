#include "setting.h"
#include "ui_setting.h"


Setting::Setting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose,true);

    ui->label_close->installEventFilter(this);
    ui->pushButton->installEventFilter(this);

    setWindowFlags(Qt::FramelessWindowHint| Qt::WindowSystemMenuHint); 
    this->setAutoFillBackground(true); // 这句要加上, 否则可能显示不出背景图.
    QPalette palette = this->palette();
    QPixmap pix;

    //qDebug()<<"begin"<<QDir::currentPath()+"/img/login_bg.jpg";
    if(pix.load(QDir::currentPath()+"/img/login_bg.jpg"))
    {
        palette.setBrush(QPalette::Window,
                         QBrush(pix.scaled( // 缩放背景图.
                                 this->size(),
                                Qt::IgnoreAspectRatio,
                                Qt::SmoothTransformation))); // 使用平滑的缩放方式
       this->setPalette(palette); // 至此, 已给widget加上了背景图.
        //qDebug()<<"success"<<QDir::currentPath()+"/img/login_bg.jpg";
    }
    else {
        qDebug()<<"failed"<<QDir::currentPath()+"/img/login_bg.jpg";
    }



}

Setting::~Setting()
{
    delete ui;
}


bool Setting::eventFilter(QObject *object, QEvent *e)
{
    if(e->type()==QEvent::MouseButtonPress&&object==ui->label_close)
    {
         close();
    }
    if(e->type()==QEvent::MouseButtonPress&&object==ui->pushButton)
    {
        if(try_saveSetting())
        {
            close();
        }

    }
    return false;
}

bool Setting::try_saveSetting()
{
    QString ip = ui->lineEdit_ip->text();
    QString port = ui->lineEdit_port->text();
    if(ip.isEmpty())
    {
        ErrBox *e = new ErrBox("请输入服务器ip地址");
        e->show();
        return false;
    }

    if(port.isEmpty())
    {
        ErrBox *e = new ErrBox("请输入服务器端口");
        e->show();
        return false;
    }

    QJsonObject json;
    json.insert("ip", ip);
    json.insert("port",port);

    QJsonDocument document;
    document.setObject(json);
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    QString json_str(byte_array);



    return true;
}
