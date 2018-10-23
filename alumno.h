#ifndef ALUMNO_H
#define ALUMNO_H

#include <QWidget>
#include <QPen>
#include <QPainter>
#include <QMediaPlayer>
namespace Ui {
class Alumno;
}

class Alumno : public QWidget
{
    Q_OBJECT

public:
    explicit Alumno(QWidget *parent = 0);
    ~Alumno();

    void alumnoConfig(QString ruta, QString nombre, bool isDesktop,QString ip,bool on,  int i = 0);

    void timerMensaje(int time);

    bool getIsOnline() const;
    void setIsOnline(bool value);

    QTimer *timer;
    QMovie *movie;
    QPen pen;
    QPainter painter;
    QMediaPlayer *player;
    QPainterPath path;

signals:
    void enviarMensaje(QString alumno);

private:
    Ui::Alumno *ui;

    QString alumno, urlCamara, mensaje;
    QImage image;

    bool isOnline, isDesktop;

protected:
    void paintEvent(QPaintEvent *e);

private slots:
    void slotMensaje();
};

#endif // ALUMNO_H
