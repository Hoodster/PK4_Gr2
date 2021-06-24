#ifndef STRONA_H
#define STRONA_H


class Strona
{
private:
    Strona* next;
    Strona* prev;
public:
    static int numerStrony;
    Strona();
    void dodajStrone(Strona **head);
};
//int Strona::numerStrony = 0;

#endif // STRONA_H
