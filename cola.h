#ifndef _COLA_
#define _COLA_ 1

#include "pedidos.h"
#include <iostream>

using namespace std;

class Node {
    private:
        Node *next;
        Node *prev;
        pedidos SuPedido;

        friend class cola;
};

class cola {
    public:
        cola(int tm = 10);
        ~cola();
        const pedidos &front();
        void enqueue(const pedidos & dt);
        void dequeue();
        bool empty() const;
        int size() const;

    private:
        Node *header;
        Node *trailer;
        int tam;
        int tamMax;
};


#endif