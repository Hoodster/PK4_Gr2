#include "strona.h"

Strona::Strona()
{

}

void Strona::dodajStrone(Strona *head)
{
    Strona *New = new Strona;
    if(head==nullptr)
    {
        head = New;
        next = nullptr;
    }
    else
    {
        New -> prev=next;
        next=New;
        if(New->prev)
            New->prev->next=New;
    }
}
