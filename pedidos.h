#ifndef _PEDIDOS_
#define _PEDIDOS_ 1

#include <iostream>

using namespace std;

struct pedidos {

    string producto[2];
    int cantidad[2];
    int numeroPedido;
    bool estado;
};


#endif