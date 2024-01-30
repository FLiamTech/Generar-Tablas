#ifndef BARRAS_H
#define BARRAS_H

#include <QMainWindow>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class Barras; }
QT_END_NAMESPACE

class Barras : public QMainWindow
{
    Q_OBJECT

public:
    Barras(QWidget *parent = nullptr);
    ~Barras();

    void promedio();
    void setColor(QPainter *painter);

private slots:
    void on_intNota1_valueChanged(int arg1);

    void on_intNota2_valueChanged(int arg1);

    void on_intNota3_valueChanged(int arg1);

    void on_promediar_clicked();

private:
    Ui::Barras *ui;

    QPixmap m_lienzo;

    void dibujar();
    int getY(int nota);
    int getAlto(int nota);
    int getPromedio();
};
#endif // BARRAS_H
