#include "principal.h"
#include "ui_principal.h"
#include <QKeyEvent>
#include <QPainter>
#include <QDebug>
#include <QTime>

Principal::Principal(QWidget *parent) :
    QWidget(parent),
    i(0),
    ui(new Ui::Principal)
{
    ui->setupUi(this);

    connect( ui->widget,SIGNAL(enviarMensaje(QString)),this, SLOT(slotMensaje(QString)));
    connect( ui->widget_2,SIGNAL(enviarMensaje(QString)),this, SLOT(slotMensaje(QString)));
    connect( ui->widget_3,SIGNAL(enviarMensaje(QString)),this, SLOT(slotMensaje(QString)));
    connect( ui->widget_4,SIGNAL(enviarMensaje(QString)),this, SLOT(slotMensaje(QString)));
    connect( ui->widget_5,SIGNAL(enviarMensaje(QString)),this, SLOT(slotMensaje(QString)));
    connect( ui->widget_6,SIGNAL(enviarMensaje(QString)),this, SLOT(slotMensaje(QString)));
    connect( ui->widget_7,SIGNAL(enviarMensaje(QString)),this, SLOT(slotMensaje(QString)));
    connect( ui->widget_8,SIGNAL(enviarMensaje(QString)),this, SLOT(slotMensaje(QString)));

    mensajes<<"Puede repetir cual es la relacion entre los hilos y los procesos?"
            <<"Como se puede matar un proceso en linux?"
            <<"Como puedo saber cuantos hilos puede correr mi computadora simultaneamente?"
            <<"Puede repetir la definicion de concurrencia?"
            <<"No entendi cuales son las formas de evitar errores debido a la concurrencia?"
            <<"Cual es el problema de que no se tenga en cuenta la concurrencia?"
            <<"Como se inicia un hilo?"
            <<"No entendi la finalidad del uso de la funcion join().";
}

void Principal::proparar()  {

    ui->widget->alumnoConfig(  ":/Recursos/Alumna.jpg","Romina Gutierrez",false,0,true);
    ui->widget_2->alumnoConfig(":/Recursos/Alumno2.jpg","Gustavo Del Rio",false,0,false);
    ui->widget_3->alumnoConfig(":/Recursos/Alumno3.jpg","German Hughes",false,0,true);
    ui->widget_4->alumnoConfig(":/Recursos/gorillaz.3gp" ,"Leandro Filippi", false, 0, true, 2);
    ui->widget_5->alumnoConfig(":/Recursos/Alumno4.jpg","Jose Rivas",false,0,true);
    ui->widget_6->alumnoConfig(":/Recursos/Alumno5.jpg","Julian Gonzalez",false,0,false);
    ui->widget_7->alumnoConfig(":/Recursos/Alumna2.jpg","  Florencia Nuñez",false,0,false);
    ui->widget_8->alumnoConfig(":/Recursos/juan.gif","Juan Pablo Calcara",false,0,true, 1);
    ui->widget_9->alumnoConfig(":/Recursos/user1.jpg","  Florencia Perez",false,0,true);

    this->repaint();
}

Principal::~Principal()
{
    delete ui;
}

void Principal::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()) {
        case Qt::Key_Escape:
            close();
            break;
            default:;
    }
}

void Principal::slotMensaje(QString alumno)
{
    int Min = 0;
    int Max = mensajes.size();

    int number = std::rand() % (Max + 1 - Min) + Min;
    emit signalMensaje(alumno,mensajes.at(number));
}

void Principal::iniciarTimer()
{
    slotMensaje( "Romina Gutierrez" );
    ui->widget_7->timerMensaje(15000);
    ui->widget_2->timerMensaje(30000);
    ui->widget_3->timerMensaje(60000);
    ui->widget_4->timerMensaje(80000);
    ui->widget_5->timerMensaje(120000);
    ui->widget_6->timerMensaje(150000);
    ui->widget->timerMensaje(230000);
}


