#ifndef ZESZYT_H
#define ZESZYT_H

#include <QObject>
#include <QString>
#include "Rozmiary.h"

class Zeszyt : public QObject
{
    Q_OBJECT
private:
    QString nazwaZeszytu = "";
public:
    explicit Zeszyt(QString nZeszytu, rozmiar rKartki, QObject *parent = nullptr);
    void ZapiszZeszyt();

    QString nazwaKatalogu = ""; // katalog, do ktorego zeszyt jest przypisany
protected:
    rozmiar rozmiarKartki;
    // lista dwukierunkowa
    //QString nazwaRozdzialu; - do klasy strony

signals:

};

#endif // ZESZYT_H
