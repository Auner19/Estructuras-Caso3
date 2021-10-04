#ifndef _QUEUE_
#define _QUEUE_

#include <iostream>
#include "pedidos.h"

using namespace std;

class Node{

    private:

        Node *next;
        Node *prev;
        Pedidos pedido;
        friend class Queue;

};

class Queue{
    
    public:

        Queue(int maxSizeQueue =100);
        const Pedidos &front();
        void enqueue(const Pedidos & pPedido);
        void dequeue();
        bool empty() const;
        int size() const;
        ~Queue();

    private:

        Node *header;
        Node *trailer;
        int tamActual;
        int tamMax;

};

//Funciones

Queue::Queue(int maxSizeQueue){

    header = new Node;
    trailer = new Node;

    trailer->prev = header;
    header->next = trailer;

    trailer->next = NULL;
    header->prev= NULL;

    tamActual = 0;
    tamMax = maxSizeQueue;

}

Queue::~Queue(){

    while(!empty())
        dequeue();

    delete header;
    delete trailer;

}

const Pedidos & Queue::front(){

    return header->next->pedido;
    
}

void Queue::enqueue(const Pedidos & pPedido){

    if(tamActual < tamMax){

        Node *nd = new Node;
        nd->pedido = pPedido;
        nd->next = trailer;
        nd->prev= trailer->prev;

        trailer->prev->next = nd;
        trailer->prev = nd;
        tamActual++;
    }
}

void Queue::dequeue(){

    if(!empty()){

        Node *nd = header->next->next;
        delete header->next;
        header->next = nd;
        nd->prev = header;
        tamActual--;
    }
}

bool Queue::empty() const{
    return(tamActual == 0);

}

int Queue::size() const{
    return(tamActual);

}

#endif

