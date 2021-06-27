#ifndef STRONA_H
#define STRONA_H


class Strona
{
private:
    Strona* next;
    Strona* prev;

public:
    static int numerStrony; // ilosc stron utworzonych w zeszycie
    static int aktualnyNrStr; // numer strony, na ktorej aktualnie jestesmy
    Strona();
    void dodajStrone(Strona **head);    // dodawania strony na koniec listy
};

#endif // STRONA_H
