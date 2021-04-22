#include "rysuj.h"
#include "ui_rysuj.h"
#include <QDebug>

Rysuj::Rysuj(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rysuj)
{
    ui->setupUi(this);
}

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
