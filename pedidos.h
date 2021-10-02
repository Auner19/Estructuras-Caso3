#ifndef _PEDIDOS_
#define _PEDIDOS_

#include <iostream>

using namespace std;

struct Pedidos {

    string producto[2];
    int cantidad[2];
    int numeroPedido;
    bool estado;
}; 

#endif