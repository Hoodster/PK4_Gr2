#ifndef ZESZYT_H
#define ZESZYT_H

#include <QObject>

class Zeszyt
{
public:
    QString nazwaZeszytu = "";
    QString nazwaKatalogu = "";
    Zeszyt();
    Zeszyt(QString nazwaZ);
};

#endif // ZESZYT_H
