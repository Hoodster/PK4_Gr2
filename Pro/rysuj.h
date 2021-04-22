#ifndef RYSUJ_H
#define RYSUJ_H

#include <QDialog>

#include <QWidget>
#include <QPoint>
#include <QMouseEvent>
#include <QPainter>
#include <QImage>
#include <QColor>

namespace Ui {
class Rysuj;
}

class Rysuj : public QDialog
{
    Q_OBJECT

public:
    explicit Rysuj(QWidget *parent = nullptr);
    ~Rysuj();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    void paintEvent(QPaintEvent *event) override;   // Updates the scribble area where we are painting

private:
    Ui::Rysuj *ui;
    int wielkoscPisaka;
    QColor kolorPisaka;
    bool rysowanie; // czy teraz uzytkownik rysuje
    QImage image;   // Stores the image being drawn

    QPoint punktRysowania; // aktualne polozenie myszki

    void Rysowanie(const QPoint &Punkt);

};

#endif // RYSUJ_H
