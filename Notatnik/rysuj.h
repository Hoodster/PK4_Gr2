#ifndef RYSUJ_H
#define RYSUJ_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QFileDialog>

class rysuj : public QWidget
{
    Q_OBJECT
public:
    explicit rysuj(QWidget *parent = nullptr);
    ~rysuj() override;

    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void resizeEvent(QResizeEvent *event) override;

    void start();

    bool otworzObraz();
    void otwieranieObrazu(QString numer);

    QImage pobierzObraz();
    void ustawObraz(QImage image);

    void resize(int w, int h);

    void clear();

    void setBrushWidth (int setBrushWidth);

    void ustawKolor(QColor setColor);
    QColor pobierzKolor();

    QColor pobierzPoprzedniKolor() const;
    void ustawPoprzedniKolor(const QColor &value);

    Qt::PenStyle getPenStyle() const;
    void setPenStyle(const Qt::PenStyle &value);

    Qt::PenCapStyle getCapStyle() const;
    void setCapStyle(const Qt::PenCapStyle &value);

    Qt::PenJoinStyle getJoinStyle() const;
    void setJoinStyle(const Qt::PenJoinStyle &value);

    QImage getCopyDrawing() const;
    void setCopyDrawing(const QImage &value);

private:
    QImage poleRysuj;
    QImage kopiaRysuj;
    QPoint mEnd;
    QPoint mBegin;
    QColor aktualnyKolor;
    QColor poprzedniKolor;
    QColor fillColor;
    Qt::PenStyle penStyle;
    Qt::PenCapStyle capStyle;
    Qt::PenJoinStyle joinStyle;

    int brushWidth;
    bool isDrawing;

    bool mousePressed;
};

#endif // RYSUJ_H
