#ifndef _BODEGA_
#define _BODEGA_ 1

#include <iostream>
#include "listadoble.h"

using namespace std;

struct bodega {

    int columnas;
    int paletasXcolumna;
    int unidadesXpaletas;
    int bodegaId;

    void* data = nullptr;
    struct bodega* next = nullptr;
    struct bodega* previous = nullptr;

    struct listadoble bodegaList;

    bool isEmpty() {
        return bodegaList.isEmpty();
    };

    void push(void* pElement) {
        bodegaList.addToBegining(pElement);
    };

    void* pop() {
        if (!bodegaList.isEmpty()) {
            return bodegaList.removeFirst();
        } else {
            return nullptr;
        }
    }

};

#endif