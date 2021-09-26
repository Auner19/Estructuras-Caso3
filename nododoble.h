#ifndef _NODODOBLE_
#define _NODODOBLE_ 1

#include <iostream>


struct bodega {
    int columnas;
    int paletasXcolumna;
    int unidadesXpaleta;

    struct listadoble PilaList;

    bool isEmpty() {
        return PilaList.isEmpty();
    };

    void push(void* pElement) {
        PilaList.addToBegining(pElement);
    };

    void* pop() {
        if (!PilaList.isEmpty()) {
            return PilaList.removeFirst();
        } else {
            return nullptr;
        }
    }
};

struct nododoble {
    struct bodega data;
    struct nododoble* next = nullptr;
    struct nododoble* previous = nullptr;
};

#endif