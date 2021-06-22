#ifndef STRONA_H
#define STRONA_H


class Strona
{
private:
    int numerStrony = 1; //static
    Strona* next;
    Strona* prev;
public:
    Strona();
    void dodajStrone(Strona **head);
};

#endif // STRONA_H
