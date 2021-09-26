#ifndef _NODODOBLE_
#define _NODODOBLE_ 1

#include <iostream>
#include "listadoble.h"

using namespace std;


struct bodega {
    int columnas;
    int paletasXcolumna;
    int unidadesXpaleta;

    struct listadoble bodegaList;

    bool isEmpty() {
        return bodegaList.isEmpty();
    };

    void push(void* pElement) {
        bodegaList.addToBegining(pElement);
    };

    void pop() {
        if (!bodegaList.isEmpty()) {
            bodegaList.removeFirst();
        } else {
            cout << "no hay datos" << endl;
        }
    }
};

struct nododoble {
    struct bodega data;
    struct nododoble* next = nullptr;
    struct nododoble* previous = nullptr;
};


#endif