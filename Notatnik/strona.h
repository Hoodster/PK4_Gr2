#ifndef STRONA_H
#define STRONA_H


class Strona
{
public:
    Strona();
    int numerStrony;
    Strona* next;
    Strona* prev;
    void dodajStrone(Strona *head);
};

#endif // STRONA_H
