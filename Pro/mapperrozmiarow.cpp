#include "mapperrozmiarow.h"

MapperRozmiarow::MapperRozmiarow()
{

}

int *MapperRozmiarow::map(rozmiar rozmiar)
{
    int *t = new int[2];
    switch (rozmiar) {
        case rozmiar::A3:
            t[0] = 1133;   // szerokosc w mm
            t[1] = 1587;   // wysokosc w mm
            break;
        case rozmiar::A4:
            t[0] = 793;
            t[1] = 1133;
            break;
        case rozmiar::A5:
            t[0] = 566;
            t[1] = 793;
            break;
    }
    return t;
}
