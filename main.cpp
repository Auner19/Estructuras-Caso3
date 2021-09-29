#include "bodega.h"
#include "listadoble.h"

#include <iostream>


using namespace std;

struct bodega pilaGeneral;

struct bodega release(int pBodegaId) {
    struct bodega result;
    struct bodega auxBodega;

    while (!pilaGeneral.isEmpty()) {
        void* top = pilaGeneral.pop();
        struct bodega* topBodega = (struct bodega*)top;

        cout << "se sacó de la pila de la bodega " << topBodega->bodegaId << endl;;
        if (topBodega->bodegaId==pBodegaId) {
            cout << "ya se encontró la bodega " << topBodega->bodegaId << endl;;
            result = *topBodega;
            break;
        } else {
            auxBodega.push(top);
            cout << "se guardó en auxiliar " << ((struct bodega*)top)->bodegaId << endl;;
        }
    }

    // result tiene la respuesta, es decir el encontrado o el default, containerid = -1
    // podria ser que auxStack tenga elementos, entonces hay que volverlos a apilar

    while (!auxBodega.isEmpty()) {
        void* top = auxBodega.pop();
        cout << "Re apilando a " << ((struct bodega*)top)->bodegaId << endl;;
        pilaGeneral.push(top);
    }

    return result;
}



int main() {

    struct bodega b1 = {5, 3, 5, 1};
    struct bodega b2 = {6, 4, 6, 2};
    struct bodega b3 = {7, 5, 7, 3};
    struct bodega b4 = {8, 6, 8, 4};

    pilaGeneral.push(&b1);
    pilaGeneral.push(&b2);
    pilaGeneral.push(&b3);
    pilaGeneral.push(&b4);

    struct bodega buscado = release(145);

    cout << buscado.bodegaId << endl;

    buscado = release(01);
    cout << buscado.bodegaId << endl;    
    buscado = release(03);
    cout << buscado.bodegaId << endl;    
    
    cout << "==============" << endl;
    buscado = release(06);
    cout << buscado.bodegaId << endl;

    //cout << "hola mundo" << endl;

}