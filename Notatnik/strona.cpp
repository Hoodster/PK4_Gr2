#include "strona.h"

Strona::Strona()
{

}
int Strona::numerStrony = 0;
int Strona::aktualnyNrStr = 1;

void Strona::dodajStrone(Strona **head)
{
    Strona *nowaStrona = new Strona;
    Strona *tmpS = *head;
    nowaStrona->numerStrony++;
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
