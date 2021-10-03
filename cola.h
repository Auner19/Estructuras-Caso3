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

    Queue(int tm =100);
    const Pedidos &front();
    void enqueue(const Pedidos & dt);
    void dequeue();
    bool empty() const;
    int size() const;
    void printFoward();
    ~Queue();

    private:
        Node *header;
        Node *trailer;
        int tam;
        int tamMax;
};

//Funciones

Queue::Queue(int tm){

    header = new Node;
    trailer = new Node;

    trailer->prev = header;
    header->next = trailer;

    trailer->next = NULL;
    header->prev= NULL;

    tam = 0;
    tamMax = tm;

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


void Queue::enqueue(const Pedidos & dt){

    if(tam < tamMax){

        Node *nd = new Node;
        nd->pedido = dt;
        nd->next = trailer;
        nd->prev= trailer->prev;

        trailer->prev->next = nd;
        trailer->prev = nd;
        tam++;
    }
}
void Queue::dequeue(){

    if(!empty()){

        Node *nd = header->next->next;
        delete header->next;
        header->next = nd;
        nd->prev = header;
        tam--;
    }
}
bool Queue::empty() const{
    return(tam == 0);
}
int Queue::size() const{
    return(tam);
}

#endif

