#include "rysuj.h"
#include <QImage>
#include <QMessageBox>
#include <QMouseEvent>
#include <QPainter>
#include <QPainterPath>


rysuj::rysuj(QWidget *parent) : QWidget(parent)
{
    start();
}


rysuj::~rysuj() {}


void rysuj::start()
{
    poleRysuj = QImage(this->size(), QImage::Format_RGB32);
    poleRysuj.fill(Qt::white);  // kolor pola do rysowania
    ustawKolor(Qt::black);  //kolor olowka
    setBrushWidth(1);   // rozmiar olowka / pedzla
    // styl rysowania olowka / pedzla
    setPenStyle(Qt::SolidLine);
    setCapStyle(Qt::RoundCap);
    setJoinStyle(Qt::RoundJoin);
    mousePressed = false;
}


bool rysuj::otworzObraz()
{
     QString lokacjaObrazu = QFileDialog::getOpenFileName(this, tr("Open image"), "", tr("PNG (*.png);;JPEG (*.jpg *.jpeg);;BMP (*.bmp)" ));
     if(!lokacjaObrazu.isEmpty())
     {
        poleRysuj.load(lokacjaObrazu);
        return true;
     }
     else
     {
         return false;
     }
}

void rysuj::otwieranieObrazu(QString numer)
{
    QString sci = "C:/rys";
    QString lokacjaObrazu = sci + "/" + numer + ".png";
    poleRysuj.load(lokacjaObrazu);
}


void rysuj::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        mBegin = event->pos();
        mEnd = event->pos();

        isDrawing = true;
        mousePressed = true;
    }
    update();
}


void rysuj::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && isDrawing)
    {
        mEnd = event->pos();
    }
    update();
}


void rysuj::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && isDrawing)
    {
        isDrawing = false;
        mousePressed = false;
    }
    update();
}


void rysuj::paintEvent(QPaintEvent *event)
{
    static bool wasMousePressed = false;

    QRect dirtyRect = event->rect();
    QPainter painter(this);
    painter.drawImage(dirtyRect, poleRysuj, dirtyRect);

    if(mousePressed)
    {
        wasMousePressed = true;


            QPainter pencilPainter(&poleRysuj);
            pencilPainter.setPen(QPen(aktualnyKolor,brushWidth,penStyle,capStyle,joinStyle));
            pencilPainter.drawLine(mEnd, mBegin);

            mBegin = mEnd;

    }
    else if(wasMousePressed)
    {
        QPainter painter(&poleRysuj);
        painter.setPen(QPen(aktualnyKolor,brushWidth,penStyle,capStyle,joinStyle));


            painter.drawImage(dirtyRect, poleRysuj, dirtyRect);


        wasMousePressed = false;
    }
    update();
}


void rysuj::resizeEvent(QResizeEvent *event)
{
    if (width() != poleRysuj.width() || height() != poleRysuj.height())
    {
        int nWidth, nHeight;

        if (width() > poleRysuj.width())
            nWidth = width();
        if (width() <= poleRysuj.width())
            nWidth = poleRysuj.width();
        if (height() > poleRysuj.height())
            nHeight = height();
        if (height() <= poleRysuj.height())
            nHeight = poleRysuj.height();

        resize(nWidth,nHeight);
    }
}


QImage rysuj::pobierzObraz()
{
    return poleRysuj;
}

void rysuj::ustawObraz(QImage image)
{
    poleRysuj = image;
}

void rysuj::resize(int w, int h)
{
    QPixmap newImage(QSize(w, h));
    newImage.fill(Qt::white);
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), poleRysuj);
    ustawObraz(newImage.toImage());
    update();
}

void rysuj::clear()
{
    poleRysuj.fill(Qt::white);
    update();
}

QColor rysuj::pobierzPoprzedniKolor() const
{
    return poprzedniKolor;
}

void rysuj::ustawPoprzedniKolor(const QColor &value)
{
    poprzedniKolor = value;
}

Qt::PenStyle rysuj::getPenStyle() const
{
    return penStyle;
}

void rysuj::setPenStyle(const Qt::PenStyle &value)
{
    penStyle = value;
}

Qt::PenCapStyle rysuj::getCapStyle() const
{
    return capStyle;
}

void rysuj::setCapStyle(const Qt::PenCapStyle &value)
{
    capStyle = value;
}

Qt::PenJoinStyle rysuj::getJoinStyle() const
{
    return joinStyle;
}

void rysuj::setJoinStyle(const Qt::PenJoinStyle &value)
{
    joinStyle = value;
}

QImage rysuj::getCopyDrawing() const
{
    return kopiaRysuj;
}

void rysuj::setCopyDrawing(const QImage &value)
{
    kopiaRysuj = value;
}

void rysuj::ustawKolor(QColor ustawKolor)
{
    aktualnyKolor = ustawKolor;
}

void rysuj::setBrushWidth(int setBrushWidth)
{
    brushWidth = setBrushWidth;
}

QColor rysuj::pobierzKolor()
{
    return aktualnyKolor;
}
