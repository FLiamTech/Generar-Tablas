#include "barras.h"
#include "ui_barras.h"

Barras::Barras(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Barras)
{
    ui->setupUi(this);
    // Creando el lienzo
    m_lienzo = QPixmap(500, 500);
    // Llamar a dibujar
    dibujar();

}

Barras::~Barras()
{
    delete ui;
}

void Barras::promedio()
{
    QPainter painter(&m_lienzo);
    QPen pincel;
    pincel.setWidth(5);
    pincel.setColor(Qt::blue);
    pincel.setJoinStyle(Qt::MiterJoin);
    painter.setPen(pincel);

    int promedioTabla = getY(getPromedio());

    painter.drawLine(50, promedioTabla, 450, promedioTabla);
    setColor(&painter);  // Pasar el QPainter como argumento
    ui->lblCuadro->setPixmap(m_lienzo);
}

void Barras::setColor(QPainter *painter)
{
    // Linea del promedio
    int promedioTabla = getY(getPromedio());

    // Coordenadas de referencia
    int x = 60;

    if (getY(ui->intNota1->value()) > promedioTabla) {
        painter->fillRect(x, getY(ui->intNota1->value()), 100, getAlto(ui->intNota1->value()), QBrush(Qt::red));
    } else {
        painter->fillRect(x, getY(ui->intNota1->value()), 100, getAlto(ui->intNota1->value()), QBrush(Qt::green));
    }

    if (getY(ui->intNota2->value()) > promedioTabla) {
        painter->fillRect(x+140, getY(ui->intNota2->value()), 100, getAlto(ui->intNota2->value()), QBrush(Qt::red));
    } else {
        painter->fillRect(x+140, getY(ui->intNota2->value()), 100, getAlto(ui->intNota2->value()), QBrush(Qt::green));
    }

    if (getY(ui->intNota3->value()) > promedioTabla) {
        painter->fillRect(x+280, getY(ui->intNota3->value()), 100, getAlto(ui->intNota3->value()), QBrush(Qt::red));
    } else {
        painter->fillRect(x+280, getY(ui->intNota3->value()), 100, getAlto(ui->intNota3->value()), QBrush(Qt::green));
    }
}

void Barras::dibujar()
{
    // Rellenar el fondo de la imagen en blanco
    m_lienzo.fill(Qt::white);
    // Crear el objeto que va a pintar
    QPainter painter(&m_lienzo);
    // Dibujar linea base
    QPen pincelBase;
    pincelBase.setWidth(5);
    pincelBase.setColor(Qt::black);
    pincelBase.setJoinStyle(Qt::MiterJoin);
    painter.setPen(pincelBase);
    painter.drawLine(50, 450, 450, 450);

    // Crea pincel para bordes
    QPen pincel;
    pincel.setWidth(5);
    pincel.setColor(Qt::gray);
    pincel.setJoinStyle(Qt::MiterJoin);
    // Establecer el pincel al pintor
    painter.setPen(pincel);

    // Coordenadas de referencia
    int x = 60;

    // Graficar primera barra
    int n = ui->intNota1->value();
    painter.drawRect(x, getY(n), 100, getAlto(n));

    // Graficar segunda barra
    int n2 = ui->intNota2->value();
    painter.drawRect(x+140, getY(n2), 100, getAlto(n2));

    // Graficar tercera barra
    int n3 = ui->intNota3->value();
    painter.drawRect(x+280, getY(n3), 100, getAlto(n3));

    ui->lblCuadro->setPixmap(m_lienzo);
}

int Barras::getY(int nota)
{
    return (450 - 4 * nota);
}

int Barras::getAlto(int nota)
{
    return (4 * nota);
}

int Barras::getPromedio()
{
    int n = ui->intNota1->value();
    int n2 = ui->intNota2->value();
    int n3 = ui->intNota3->value();

    return (n + n2 + n3) / 3;
}


void Barras::on_intNota1_valueChanged(int arg1)
{
    dibujar();
}


void Barras::on_intNota2_valueChanged(int arg1)
{
    dibujar();
}


void Barras::on_intNota3_valueChanged(int arg1)
{
    dibujar();
}

void Barras::on_promediar_clicked()
{
    promedio();
}

