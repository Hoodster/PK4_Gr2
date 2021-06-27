#ifndef STRONA_H
#define STRONA_H


class Strona
{


public:
    Strona* next;
    Strona* prev;
    static int numerStrony;
    static int aktualnyNrStr; // numer strony, na ktorym aktualnie jestesmy
    Strona();
    void dodajStrone(Strona **head);
};

#endif // STRONA_H
