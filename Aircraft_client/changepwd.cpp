#include "changepwd.h"
#include "ui_changepwd.h"



ChangePwd::ChangePwd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangePwd)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose,true);
    setWindowFlags(Qt::FramelessWindowHint| Qt::WindowSystemMenuHint);
    ui->label_close->installEventFilter(this);
    ui->pushButton->installEventFilter(this);



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

ChangePwd::~ChangePwd()
{
    delete ui;
}

bool ChangePwd::eventFilter(QObject *object, QEvent *e)
{
    if(e->type()==QEvent::MouseButtonPress&&object==ui->label_close)
    {
         close();
    }

    if(e->type()==QEvent::MouseButtonPress&&object==ui->pushButton)
    {
        if(try_changepwd())
         close();
    }
    return false;
}

bool ChangePwd::try_changepwd()
{
    QString username = ui->lineEdit_userName->text();
    QString oldpwd = ui->lineEdit_oldPwd->text();
    QString newpwd = ui->lineEdit_newPwd->text();
    QString newpwd2 = ui->lineEdit_newPwd2->text();

    if(username.isEmpty())
    {
        ErrBox *e = new ErrBox("请输入用户名");
        e->show();
        return false;
    }

    if(oldpwd.isEmpty())
    {
        ErrBox *e = new ErrBox("请输入原密码");
        e->show();
        return false;
    }

    if(newpwd.isEmpty())
    {
        ErrBox *e = new ErrBox("请输入新密码");
        e->show();
        return false;
    }

    if(newpwd2.isEmpty())
    {
        ErrBox *e = new ErrBox("请确认新密码");
        e->show();
        return false;
    }

    if(newpwd.compare(newpwd2))
    {
        ErrBox *e = new ErrBox("新密码不一致");
        e->show();
        return false;
    }

    //连接服务器修改

    return true;
}
