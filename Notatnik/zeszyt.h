#ifndef ZESZYT_H
#define ZESZYT_H

#include <QObject>
#include "strona.h"

class Zeszyt
{
public:
    QString nazwaZeszytu = "";
    QString nazwaKatalogu = "";
    Strona *strona = nullptr;
    Zeszyt();
    Zeszyt(QString nazwaZ);
    void dodajZeszyt(QString nazwaZ);
};

#endif // ZESZYT_H
