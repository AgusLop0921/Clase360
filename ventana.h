#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QKeyEvent>
#include <QString>

#include "alumno.h"

namespace Ui {
class Ventana;
}

class Ventana : public QWidget
{
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = 0);
    ~Ventana();

    QString mensaje, salida;
    QImage  *imageCopia;

private slots:
    void  recibirMensaje(QString alumno, QString mensaje);

private:
    Ui::Ventana *ui;
    QImage* image;
    QString color;

    int i;

    void keyPressEvent(QKeyEvent *e);

    void empezarPreguntas();

protected:
    void paintEvent(QPaintEvent * e);

signals:
    void signalEmpezarPreguntas();

};

#endif // VENTANA_H
