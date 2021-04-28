#include "rysuj2.h"
#include "ui_rysuj2.h"
#include "notatnik.h"
#include <QInputDialog>
#include <QColorDialog>
#include <QScreen>
#include <QPaintEvent>
#include <QPainter>
#include <QImage>
#include <QMouseEvent>
#include <QFile>
#include <QTextStream>
#include <QBuffer>

#define DEFAULT_SIZE 5

rysuj2::rysuj2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::rysuj2)
{
    ui->setupUi(this);
    mImage = new QImage(QGuiApplication::primaryScreen()->size(), QImage::Format_ARGB32);
    mPainter = new QPainter(mImage);
    mEnabled = false;
    mColor = QColor(Qt::black);
    mSize = DEFAULT_SIZE;
}

rysuj2::~rysuj2(){
    delete ui;
    delete mPainter;
    delete mImage;

}

void rysuj2::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    painter.fillRect(mImage->rect(), Qt::white);    //ustawienie koloru tla
    painter.drawImage(0, 0, *mImage);
    e->accept();
}

void rysuj2::mousePressEvent(QMouseEvent *e){
    mEnabled = true;
    mBegin = e->pos();
    e->accept();
}

void rysuj2::mouseMoveEvent(QMouseEvent *e){
    if (!mEnabled){
        e->accept();
        return;
    }
    QPen pen(mColor);
    pen.setCapStyle(Qt::RoundCap);
    pen.setWidth(mSize);
    mEnd = e->pos();
    mPainter->setPen(pen);
    mPainter->drawLine(mBegin, mEnd);
    mBegin = mEnd;
    update();
    e->accept();
}

void rysuj2::mouseReleaseEvent(QMouseEvent *e){
    mEnabled = false;
    e->accept();
}

void rysuj2::on_actionRozmiar_triggered()
{
    mSize = QInputDialog::getInt(this, "rozmiar olowka", "wprowadz rozmiar:",5);
}

void rysuj2::on_actionColor_triggered()
{
    mColor = QColorDialog::getColor(Qt::black,this, "kolor olowka");
}


void rysuj2::on_actionzapiszprojekt_triggered()
{



}

void rysuj2::on_actionZamkniecie_triggered()
{
    close();
    QMainWindow *n = new Notatnik;
    n->show();
}

void rysuj2::on_actionRozmiar_2_triggered()
{
    mSize = QInputDialog::getInt(this, "rozmiar olowka", "wprowadz rozmiar:",5);
    mColor = QColor(Qt::white);
}
