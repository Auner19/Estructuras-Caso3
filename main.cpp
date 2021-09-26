#include "nododoble.h"
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

        cout << "saque de la pila de la bodega " << topBodega->bodegaId << endl;;
        if (topBodega->bodegaId==pBodegaId) {
            cout << "ya encontré la bodega " << topBodega->bodegaId << endl;;
            result = *topBodega;
            break;
        } else {
            auxBodega.push(top);
            cout << "guardo en auxiliar " << ((struct bodega*)top)->bodegaId << endl;;
        }
    }

    // result tiene la respuesta, es decir el encontrado o el default, containerid = -1
    // podria ser que auxStack tenga elementos, entonces hay que volverlos a apilar

    while (!auxBodega.isEmpty()) {
        void* top = auxBodega.pop();
        cout << "re apilando a " << ((struct bodega*)top)->bodegaId << endl;;
        pilaGeneral.push(top);
    }

    return result;
}



int main() {

    struct bodega b1 = {5, 3, 5, 01};
    struct bodega b2 = {6, 4, 6, 02};
    struct bodega b3 = {7, 5, 7, 03};
    struct bodega b4 = {8, 6, 8, 04};

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