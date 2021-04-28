#include "zeszyt.h"

Zeszyt::Zeszyt(QString nZeszytu, rozmiar rKartki, QObject *parent) : QObject(parent)
{
    nazwaZeszytu = nZeszytu;
    rozmiarKartki = rKartki;
}
