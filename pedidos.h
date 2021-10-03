#ifndef _PEDIDOS_
#define _PEDIDOS_

#include <iostream>

using namespace std;

struct Pedidos {

    string producto;
    int cantidad;
    int numeroPedido;
    mutable bool estado;
}; 

#endif