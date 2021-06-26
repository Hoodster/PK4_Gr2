#ifndef STRONA_H
#define STRONA_H


class Strona
{
private:
    Strona* next;
    Strona* prev;
public:
    static int numerStrony;
    static int aktualnyNrStr; // numer strony, na ktorym aktualnie jestesmy
    Strona();
    void dodajStrone(Strona **head);
};

#endif // STRONA_H
