#include "widget.h"
#include "ui_widget.h"
#include <QLayout>
#include <QPushButton>
#include <cmath>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    this->waitFor = false;
    this->justDisplay = false;
    this->op = NullOp;

    //this->setFixedSize(1,1);//minimum size would be sat
    ui->setupUi(this);
    QVBoxLayout* l = new QVBoxLayout;
    this->setLayout(l);
    //l->setMargin(10);
    //l->setAlignment(Qt::AlignTop);
    //l->setContentsMargins(60,10,120,90);
    this->setWindowTitle("Calculator(Alone7)");
    this->setStyleSheet("QWidget,QPushButton{background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
                        "stop:0 rgb(152,184,201), stop: 0.6 rgb(152,184,201), stop:1 rgb(111,155,179))"
                        ";color:white;font-size: 16px;}"
                        "QPushButton:hover{background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
                        "stop:0 rgb(80,125,150), stop: 0.6 rgb(80,125,150), stop:1 rgb(111,155,179))"
                        ";color:white;font-size: 16px;}"
                        "QPushButton:pressed{background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
                        "stop:0 rgb(100,150,170), stop: 0.6 rgb(100,150,170), stop:1 rgb(111,155,179))"
                        ";color:white;font-size: 16px;}"
                        "QLabel{background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
                        "stop:0 rgb(152,184,201), stop: 0.6 rgb(152,184,201), stop:1 rgb(111,155,179));color:white;"
                        "border: 1px solid rgb(111,155,179);"
                        "font-size: 26px;padding: 0px}");

    this->lbl = new QLabel("0");
    this->lbl->setAlignment(Qt::AlignRight);
    //this->lbl->setStyleSheet("margin: 60px;font-size: 26px");
    this->lbl->setTextFormat(Qt::MarkdownText);
    this->lbl->setTextInteractionFlags(Qt::TextSelectableByMouse);
    this->lbl->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    l->addWidget(this->lbl);

    this->history = new QLabel("");
    this->history->setAlignment(Qt::AlignLeft);
    //this->history->setTextFormat(Qt::MarkdownText);
    this->history->setStyleSheet("background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
                        "stop:0 rgb(152,184,201), stop: 0.6 rgb(152,184,201),"
                        " stop:1 rgb(111,155,179));color:white;"
                        "border: 1px solid rgb(111,155,179);"
                        "font-size: 14px;padding-bottom:20px;text-align: left;");
    l->addWidget(this->history);

    QPushButton* pb9 = new QPushButton(u8"9");
    QPushButton* pb8 = new QPushButton(u8"8");
    QPushButton* pb7 = new QPushButton(u8"7");
    QPushButton* pb6 = new QPushButton(u8"6");
    QPushButton* pb5 = new QPushButton(u8"5");
    QPushButton* pb4 = new QPushButton(u8"4");
    QPushButton* pb3 = new QPushButton(u8"3");
    QPushButton* pb2 = new QPushButton(u8"2");
    QPushButton* pb1 = new QPushButton(u8"1");
    QPushButton* pb0 = new QPushButton(u8"0");
    QPushButton* backspace = new QPushButton(u8"\u2936");
    QPushButton* rootSquare = new QPushButton(u8"\u221A");
    QPushButton* clear = new QPushButton(u8"Clear");
    QPushButton* add = new QPushButton(u8"+");
    QPushButton* subtract = new QPushButton(u8"-");
    QPushButton* multiply = new QPushButton(u8"x");
    QPushButton* divide = new QPushButton(u8"/");
    QPushButton* reminder = new QPushButton(u8"%");
    QPushButton* _1_x = new QPushButton(u8"1/x");
    QPushButton* equal = new QPushButton(u8"=");
    QPushButton* dot = new QPushButton(u8".");

    QObject::connect(pb0,&QPushButton::clicked,[this](){
        if(this->lbl->text() == "0")
            return;
        this->lbl->setText(lbl->text()+"0");
        this->history->setText(history->text()+"0");
    });
    QObject::connect(pb1,&QPushButton::clicked,[this](){
        if(this->lbl->text() == "0" || this->justDisplay)
            this->lbl->setText("");
        this->lbl->setText(lbl->text()+"1");
        this->history->setText(history->text()+"1");
    });
    QObject::connect(pb2,&QPushButton::clicked,[this](){
        if(this->lbl->text() == "0" || this->justDisplay)
            this->lbl->setText("");
        this->lbl->setText(lbl->text()+"2");
        this->history->setText(history->text()+"2");
    });
    QObject::connect(pb3,&QPushButton::clicked,[this](){
        if(this->lbl->text() == "0" || this->justDisplay)
            this->lbl->setText("");
        this->lbl->setText(lbl->text()+"3");
        this->history->setText(history->text()+"3");
    });
    QObject::connect(pb4,&QPushButton::clicked,[this](){
        if(this->lbl->text() == "0" || this->justDisplay)
            this->lbl->setText("");
        this->lbl->setText(lbl->text()+"4");
        this->history->setText(history->text()+"4");
    });
    QObject::connect(pb5,&QPushButton::clicked,[this](){
        if(this->lbl->text() == "0" || this->justDisplay)
            this->lbl->setText("");
        this->lbl->setText(lbl->text()+"5");
        this->history->setText(history->text()+"5");
    });
    QObject::connect(pb6,&QPushButton::clicked,[this](){
        if(this->lbl->text() == "0" || this->justDisplay)
            this->lbl->setText("");
        this->lbl->setText(lbl->text()+"6");
        this->history->setText(history->text()+"6");
    });
    QObject::connect(pb7,&QPushButton::clicked,[this](){
        if(this->lbl->text() == "0" || this->justDisplay)
            this->lbl->setText("");
        this->lbl->setText(lbl->text()+"7");
        this->history->setText(history->text()+"7");
    });
    QObject::connect(pb8,&QPushButton::clicked,[this](){
        if(this->lbl->text() == "0" || this->justDisplay)
            this->lbl->setText("");
        this->lbl->setText(lbl->text()+"8");
        this->history->setText(history->text()+"8");
    });
    QObject::connect(pb9,&QPushButton::clicked,[this](){
        if(this->lbl->text() == "0" || this->justDisplay)
            this->lbl->setText("");
        this->lbl->setText(lbl->text()+"9");
        this->history->setText(history->text()+"9");
    });
    QObject::connect(backspace,&QPushButton::clicked,[this](){
        QString temp="";
        for(int i=0;i<this->lbl->text().size()-1;i++){
            temp += this->lbl->text()[i];
        }
        if(temp == ""){
            this->lbl->setText("0");
        }
        else{
            this->lbl->setText(temp);
            this->history->setText(this->history->text().remove(this->history->text().size()-1,1));
        }
        if(temp == "" && !this->history->text().isEmpty() &&
                QChar(this->history->text().at(this->history->text().size()-1)).isDigit()){
            this->history->setText(this->history->text().remove(this->history->text().size()-1,1));
        }
    });
    QObject::connect(rootSquare,&QPushButton::clicked,[this](){
        this->lbl->setNum(sqrt(this->lbl->text().toDouble()));
        this->history->setText("");
    });
    QObject::connect(clear,&QPushButton::clicked,[this](){
        this->lbl->setText("0");
        this->history->setText("");
        this->waitFor = false;
        this->justDisplay = false;
        this->op = NullOp;
    });
    QObject::connect(add,&QPushButton::clicked,[this](){
        if(this->op != NullOp && this->op != Add){
            switch(this->op){
            case Add:
                this->firstOp = this->firstOp+this->lbl->text().toDouble();
                this->lbl->setText(QString::number(this->firstOp));
                this->justDisplay = true;
                break;
            case Subtract:
                this->firstOp = this->firstOp-this->lbl->text().toDouble();
                this->lbl->setText(QString::number(this->firstOp));
                this->justDisplay = true;
                break;
            case Multiply:
                this->firstOp = this->firstOp*this->lbl->text().toDouble();
                this->lbl->setText(QString::number(this->firstOp));
                this->justDisplay = true;
                break;
            case Divide:
                this->firstOp = this->firstOp/this->lbl->text().toDouble();
                this->lbl->setText(QString::number(this->firstOp));
                this->justDisplay = true;
                break;
            case Reminder:
                this->firstOp = (int)this->firstOp%(int)this->lbl->text().toDouble();
                this->lbl->setText(QString::number(this->firstOp));
                this->justDisplay = true;
                break;
            case NullOp:
                //nop
                break;
            }
        }
        else if(this->waitFor){
            if(this->lbl->text() == "")
                return;
            this->firstOp = this->firstOp+this->lbl->text().toDouble();
            this->lbl->setText(QString::number(this->firstOp));
            this->justDisplay = true;
        }else{
            this->firstOp = this->lbl->text().toDouble();
            this->lbl->setText("");
            this->waitFor = true;
        }
        this->history->setText(this->history->text()+"+");
        this->op = Add;
    });
    QObject::connect(subtract,&QPushButton::clicked,[this](){

        if(this->waitFor){
            if(this->lbl->text() == "")
                return;
            this->firstOp = this->firstOp-this->lbl->text().toDouble();
            this->lbl->setText(QString::number(this->firstOp));
            this->justDisplay = true;
        }else{
            this->firstOp = this->lbl->text().toDouble();
            this->lbl->setText("");
            this->waitFor = true;
        }
        this->history->setText(this->history->text()+"-");
        this->op = Subtract;
    });
    QObject::connect(multiply,&QPushButton::clicked,[this](){

        if(this->waitFor){
            if(this->lbl->text() == "")
                return;
            this->firstOp = this->firstOp*this->lbl->text().toDouble();
            this->lbl->setText(QString::number(this->firstOp));
            this->justDisplay = true;
        }else{
            this->firstOp = this->lbl->text().toDouble();
            this->lbl->setText("");
            this->waitFor = true;
        }
        this->history->setText(this->history->text()+"*");
        this->op = Multiply;
    });
    QObject::connect(divide,&QPushButton::clicked,[this](){
        if(this->waitFor){
            if(this->lbl->text() == "")
                return;
            this->firstOp = this->firstOp/this->lbl->text().toDouble();
            this->lbl->setText(QString::number(this->firstOp));
            this->justDisplay = true;
        }else{
            this->firstOp = this->lbl->text().toDouble();
            this->lbl->setText("");
            this->waitFor = true;
        }
        this->history->setText(this->history->text()+"/");
        this->op = Divide;
    });
    QObject::connect(reminder,&QPushButton::clicked,[this](){
        this->op = Reminder;
        if(this->waitFor){
            if(this->lbl->text() == "")
                return;
            this->firstOp = (int)this->firstOp%(int)this->lbl->text().toDouble();
            this->lbl->setText(QString::number(this->firstOp));
            this->justDisplay = true;
        }else{
            this->firstOp = this->lbl->text().toDouble();
            this->lbl->setText("");
            this->waitFor = true;
        }
    });
    QObject::connect(_1_x,&QPushButton::clicked,[this](){
        if(this->lbl->text() == "")
            return;
        this->lbl->setText(QString::number((double)1/this->lbl->text().toDouble()));
        this->history->setText("");
    });
    QObject::connect(equal,&QPushButton::clicked,[this](){
        switch(this->op){
        case Add:
            this->firstOp = this->firstOp+this->lbl->text().toDouble();
            this->lbl->setText(QString::number(this->firstOp));
            this->justDisplay = true;
            break;
        case Subtract:
            this->firstOp = this->firstOp-this->lbl->text().toDouble();
            this->lbl->setText(QString::number(this->firstOp));
            this->justDisplay = true;
            break;
        case Multiply:
            this->firstOp = this->firstOp*this->lbl->text().toDouble();
            this->lbl->setText(QString::number(this->firstOp));
            this->justDisplay = true;
            break;
        case Divide:
            this->firstOp = this->firstOp/this->lbl->text().toDouble();
            this->lbl->setText(QString::number(this->firstOp));
            this->justDisplay = true;
            break;
        case Reminder:
            this->firstOp = (int)this->firstOp%(int)this->lbl->text().toDouble();
            this->lbl->setText(QString::number(this->firstOp));
            this->justDisplay = true;
            break;
        case NullOp:
            //nop
            break;
        }
        this->waitFor = false;
        this->op = NullOp;
        this->history->setText("");
    });

    QHBoxLayout* l1 = new QHBoxLayout;
    l1->addWidget(backspace);
    l1->addWidget(rootSquare);
    l1->addWidget(clear);
    l->addLayout(l1);
    l1->setContentsMargins(0,30,0,0);

    QHBoxLayout* l2 = new QHBoxLayout;
    l2->addWidget(pb7);
    l2->addWidget(pb8);
    l2->addWidget(pb9);
    l2->addWidget(divide);
    l2->addWidget(reminder);
    l->addLayout(l2);

    QHBoxLayout* l3 = new QHBoxLayout;
    l3->addWidget(pb4);
    l3->addWidget(pb5);
    l3->addWidget(pb6);
    l3->addWidget(multiply);
    l3->addWidget(_1_x);
    l->addLayout(l3);

    QGridLayout* l4 = new QGridLayout;
    l4->addWidget(pb1,0,0);
    l4->addWidget(pb2,0,1);
    l4->addWidget(pb3,0,2);
    l4->addWidget(subtract,0,3);
    l4->addWidget(equal,0,4,2,1);
    equal->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    l4->addWidget(pb0,1,0,1,2);
    l4->addWidget(dot,1,2);
    l4->addWidget(add,1,3);
    l->addLayout(l4);

    //l->setStretchFactor(this->lbl,1);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    this->setFixedSize(400,400);
}

