#include "mapperrozmiarow.h"

MapperRozmiarow::MapperRozmiarow()
{

}

int *MapperRozmiarow::map(rozmiar rozmiar)
{
    int *t = new int[2];
    switch (rozmiar) {
        case rozmiar::A3:
            t[0] = 300;   // szerokosc
            t[1] = 420;   // wysokosc
            break;
        case rozmiar::A4:
            t[0] = 210;
            t[1] = 300;
            break;
        case rozmiar::A5:
            t[0] = 150;
            t[1] = 210;
            break;
    }
    return t;
}
