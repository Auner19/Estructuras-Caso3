#ifndef _BODEGA_
#define _BODEGA_ 1

#include <iostream>

using namespace std;

class bodega {

    private:
        int *arr;
        int indexTop;
        int maxSize;
        int columnas;
        int paletasXcolumna;
        int unidadesXpaletas;
        int bodegaId;

    public:
        bodega(int maxSize = 15);
        int size() const;
        bool empty() const;
        int top() const;
        void push(int columnas, int paletasXcolumna, int unidadesXpaletas, string producto);
        void pop();
        ~bodega();
};

#endif