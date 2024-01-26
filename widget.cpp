#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->new_window=new Form();
    //信号和槽实现两个页面的切换
    connect(ui->pushButton,&QPushButton::clicked,this,[=](){
        this->hide();
        this->new_window->show();
    });
    //点击主页面的返回按钮时，回给登陆界面一个信号，接收信号后实现页面的切换
    connect(this->new_window,&Form::back,this,[=](){
        this->new_window->hide();
        this->show();
    });
}

Widget::~Widget()
{
    delete ui;
}

