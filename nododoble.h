#ifndef _NODODOBLE_
#define _NODODOBLE_ 1

#include <iostream>


struct bodega {
    int columnas;
    int paletasXcolumna;
    int unidadesXpaleta;
};

struct nododoble {
    struct bodega data;
    struct nododoble* next = nullptr;
    struct nododoble* previous = nullptr;
};

#endif