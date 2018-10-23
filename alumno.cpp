#include "alumno.h"
#include "ui_alumno.h"
#include <QTimer>
#include <QPainter>
#include <QImage>
#include <QDebug>
#include <QMovie>

Alumno::Alumno(QWidget *parent) :QWidget(parent),
                                 alumno("Empty"),
                                 isDesktop(false),
                                 urlCamara(""),
                                 isOnline(false),
                                 ui(new Ui::Alumno)
{
    ui->setupUi(this);

    image.load(":/Recursos/usuario.jpg");
    ui->label->setText(alumno);
    ui->label->move((this->width()/2)-20,150);

}
Alumno::~Alumno()
{
    delete ui;
}

void Alumno::alumnoConfig(QString ruta, QString nombre, bool desk, QString url, bool on, int i)
{
    image.load(ruta);
    alumno = nombre;
    isOnline = on;
    isDesktop = desk;
    ui->label->setText(alumno);
    urlCamara = url;

    if ( i == 1 )  {

        movie = new QMovie(":/Recursos/juan.gif");
        movie->setScaledSize(QSize(this->width()-50, this->height()-20));
        movie->start();

        ui->lGif->setMovie(movie);
    }
    if ( i == 2 )  {

        player = new QMediaPlayer;
    }


    this->repaint();
}

void Alumno::timerMensaje(int time)
{
    if(time != 0 )
    {
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(slotMensaje()));
        timer->start(time);
    }
}

bool Alumno::getIsOnline() const
{
    return isOnline;
}

void Alumno::setIsOnline(bool value)
{
    isOnline = value;
}
void Alumno::paintEvent(QPaintEvent * e )
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    path.addRoundedRect(QRectF(10, 0, this->width()-30, this->height()-30), 10, 10);

    pen.setColor(Qt::black);
    pen.setWidth(3);
    painter.setPen(pen);

    if(isOnline) painter.fillPath(path, Qt::green);
    else painter.fillPath(path, Qt::red);

    painter.drawPath(path);
    painter.drawImage(20, 10, image.scaled(this->width()-50, this->height()-50));
}

void Alumno::slotMensaje()
{
    emit enviarMensaje(alumno);
}

