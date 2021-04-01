#ifndef NOTATNIK_H
#define NOTATNIK_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Notatnik; }
QT_END_NAMESPACE

class Notatnik : public QMainWindow
{
    Q_OBJECT

public:
    Notatnik(QWidget *parent = nullptr);
    ~Notatnik();

private:
    Ui::Notatnik *ui;
};
#endif // NOTATNIK_H
