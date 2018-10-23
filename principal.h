#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QWidget>
#include <QVector>
#include <QKeyEvent>

#include "alumno.h"

namespace Ui {
class Principal;
}

class Principal : public QWidget
{
    Q_OBJECT

public:
    explicit Principal(QWidget *parent = 0);
    ~Principal();

    void iniciarTimer();

    void proparar();
private:
    Ui::Principal *ui;

    QVector<QString> mensajes;
    int i;
    void keyPressEvent(QKeyEvent *e);

private slots:
    void slotMensaje(QString alumno);

signals:
    void signalMensaje(QString,QString);
};

#endif // PRINCIPAL_H
