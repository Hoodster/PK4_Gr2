#include "rysuj.h"
#include "ui_rysuj.h"
#include <QInputDialog>
#include <QColorDialog>
#include <QScreen>
#include <QPaintEvent>
#include <QPainter>
#include <QImage>
#include <QMouseEvent>

#define DEFAULT_SIZE 5

Rysuj::Rysuj(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rysuj)
{
    ui->setupUi(this);
//    mImage = new QImage(800, 300, QImage::Format_ARGB32);
    mImage = new QImage(QGuiApplication::primaryScreen()->size(), QImage::Format_ARGB32);
    mPainter = new QPainter(mImage);
    mEnabled = false;
    mColor = QColor(Qt::black);
    mSize = DEFAULT_SIZE;
}

Rysuj::~Rysuj(){
    delete ui;
    delete mPainter;
    delete mImage;

}

void Rysuj::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    painter.fillRect(mImage->rect(), Qt::white);
    painter.drawImage(0, 0, *mImage);
    e->accept();
}

void Rysuj::mousePressEvent(QMouseEvent *e){
    mEnabled = true;
    mBegin = e->pos();
    e->accept();
}

void Rysuj::mouseMoveEvent(QMouseEvent *e){
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

void Rysuj::mouseReleaseEvent(QMouseEvent *e){
    mEnabled = false;
    e->accept();
}

/*
// If a mouse button is pressed check if it was the
// left button and if so store the current position
// Set that we are currently drawing
void Rysuj::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        punktRysowania = event->pos();
        rysowanie = true;
    }
}

// When the mouse moves if the left button is clicked
// we call the drawline function which draws a line
// from the last position to the current
void Rysuj::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && rysowanie)
        Rysowanie(event->pos());
}

// If the button is released we set variables to stop drawing
void Rysuj::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && rysowanie) {
        Rysowanie(event->pos());
        rysowanie = false;
    }
}
// QPainter provides functions to draw on the widget
// The QPaintEvent is sent to widgets that need to
// update themselves
void Rysuj::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    // Returns the rectangle that needs to be updated
    QRect dirtyRect = event->rect();

    // Draws the rectangle where the image needs to
    // be updated
    painter.drawImage(dirtyRect, image, dirtyRect);
}

void Rysuj::Rysowanie(const QPoint &Punkt)
{
    qDebug() << Punkt.x();

    // Used to draw on the widget
    QPainter painter(&image);

    // Draw a line from the last registered point to the current
    painter.drawLine(punktRysowania, Punkt);
    painter.setPen(QPen(QColor(100, 100, 100, 127), wielkoscPisaka, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    int rad = (wielkoscPisaka / 2) + 2;

    // Call to update the rectangular space where we drew
    update(QRect(punktRysowania, Punkt).normalized().adjusted(-rad, -rad, +rad, +rad));
    // Update the last position where we left off drawing
    punktRysowania = Punkt;
}


Rysuj::~Rysuj()
{
    delete ui;
}
*/
