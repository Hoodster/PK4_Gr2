#ifndef ZESZYT_H
#define ZESZYT_H

#include <QObject>
#include <QString>
#include "Rozmiary.h"

class Zeszyt : public QObject
{
    Q_OBJECT
public:
    explicit Zeszyt(QObject *parent = nullptr);
    void DodajZeszyt();
    void UsunZeszyt();
    void ZapiszZeszyt();

    QString nazwaKatalogu = ""; // katalog, do ktorego zeszyt jest przypisany
protected:
    rozmiar rozmiarKartki;
    // lista dwukierunkowa
    //QString nazwaRozdzialu; - do klasy strony

signals:

};

#endif // ZESZYT_H
