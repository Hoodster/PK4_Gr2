#include "strona.h"

Strona::Strona()
{

}

void Strona::dodajStrone(Strona **head)
{
    Strona *nowaStrona = new Strona;
    Strona *tmpS = *head;
    nowaStrona->numerStrony += 1;
    nowaStrona->next = nullptr;

    if (*head == nullptr) {
        nowaStrona->prev = nullptr;
        *head = nowaStrona;
        return;
    }
    while (tmpS->next != nullptr)
        tmpS = tmpS->next;

    tmpS->next = nowaStrona;

    nowaStrona->prev = tmpS;

    return;
}
