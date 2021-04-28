#ifndef RYSUJ2_H
#define RYSUJ2_H

#include <QMainWindow>

namespace Ui {
class rysuj2;
}

class QPainter;
class QImage;

class rysuj2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit rysuj2(QWidget *parent = nullptr);
    ~rysuj2();
protected:
    void mousePressEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
    void paintEvent(QPaintEvent *e) override;
private slots:
    void on_actionRozmiar_triggered();
    void on_actionColor_triggered();
    void on_actionZamkniecie_triggered();
    void on_actionzapiszprojekt_triggered();
    void on_actionRozmiar_2_triggered();

private:
    Ui::rysuj2 *ui;
    QPainter *mPainter;
    QImage *mImage;      //obraz na ktorym malujemy
    QPoint mBegin;      //poczatek rysowania kursorem
    QPoint mEnd;        //koniec rysowania kursorem
    QColor mColor;      //kolor
    bool mEnabled;      //aktywacja
    int mSize;      //rozmiar
};

#endif // RYSUJ2_H
