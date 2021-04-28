#ifndef RYSUJ_H
#define RYSUJ_H

#include <QDialog>

namespace Ui {
class Rysuj;
}

class QPainter;
class QImage;

class Rysuj : public QDialog
{
    Q_OBJECT

public:
    explicit Rysuj(QWidget *parent = nullptr);
    ~Rysuj();

protected:
        void mousePressEvent(QMouseEvent *e) override;
        void mouseMoveEvent(QMouseEvent *e) override;
        void mouseReleaseEvent(QMouseEvent *e) override;
        void paintEvent(QPaintEvent *e) override;

private:
    Ui::Rysuj *ui;
    QPainter *mPainter;
    QImage *mImage;
    QPoint mBegin;
    QPoint mEnd;
    QColor mColor;
    bool mEnabled;
    int mSize;

};

#endif // RYSUJ_H
