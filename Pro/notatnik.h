#ifndef NOTATNIK_H
#define NOTATNIK_H

#include <QMainWindow>
//#include "Rozmiary.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Notatnik; }
QT_END_NAMESPACE

class Notatnik : public QMainWindow
{
    Q_OBJECT

public:
    Notatnik(QWidget *parent = nullptr);
    ~Notatnik();

private slots:
    void on_kartkaA3_triggered();

protected:
    //rozmiar rozmiary;
private:
    Ui::Notatnik *ui;
};
#endif // NOTATNIK_H
