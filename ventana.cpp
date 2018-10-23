#include "ventana.h"
#include "ui_ventana.h"
#include <QDebug>
#include <QTime>

Ventana::Ventana(QWidget *parent) :
    QWidget(parent),
    i(0),
    ui(new Ui::Ventana)
{
    ui->setupUi(this);

    QPalette p = ui->textEdit->palette();
    p.setColor(QPalette::Base, QColor(0,0,0,0)); // r,g,b,A
    ui->textEdit->setPalette(p);

    image = new QImage(":/Recursos/fondo2.jpg");

    connect(ui->widget,SIGNAL(signalMensaje(QString,QString)),this, SLOT(recibirMensaje(QString,QString)));
}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::recibirMensaje(QString alumno,QString mensaje)
{
    salida.insert(0,"[");
    salida.append(QTime::currentTime().toString());
    salida.append("] ");
    salida.append(alumno);
    salida.append(" : ");
    salida.append(mensaje);

    if(i<3)
    {
        if(i==0) color = "red";
        if(i==1) color = "green";
        else color = "blue";
        i++;
    }
    else {i=1;color="red";}

    ui->textEdit->setTextColor(QColor(color));
    ui->textEdit->append(salida);

}
void Ventana::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()) {
        case Qt::Key_Escape:
            close();
            break;
    case Qt::Key_A:
            ui->widget->iniciarTimer();
            break;

    case Qt::Key_P:
            ui->widget->proparar();
            break;
            default:;
    }
}

void Ventana::paintEvent(QPaintEvent *e)
{
//    QPainter* painter = new QPainter(this);
//    imageCopia = new QImage(image->scaled(this->width(),this->height()));
//    painter->drawImage(0, 0, *imageCopia);
}
