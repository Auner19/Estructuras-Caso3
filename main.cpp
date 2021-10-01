#include "bodega.h"
#include "pedidos.h"
#include "cola.h"

#include <iostream>

using namespace std;


bodega::bodega(int max){
    indexTop = -1;
    maxSize = max;
    arr = new int[max];
}

int bodega::size() const{
    return indexTop +1;
}

bool bodega::empty() const{
    return(indexTop == -1);
}

int bodega::top() const{
    return arr[indexTop];
}

void bodega::push(int columnas, int paletasXcolumna, int unidadesXpaletas, string producto){
    if(indexTop +1 < maxSize)
        arr[++indexTop] = columnas, paletasXcolumna, unidadesXpaletas, producto;
}

void bodega::pop(){
    if(!empty())
        indexTop--;
}

bodega::~bodega(){
    delete []arr;
}

cola::cola(int tm){
    header = new Node;
    trailer = new Node;
    header->next = trailer;
    trailer->prev = header;
    header->prev = NULL;
    trailer->next = NULL;

    tam = 0;
    tamMax = tm;
}

cola::~cola(){
    while(!empty())
        dequeue();

    delete header;
    delete trailer;
}

const pedidos & cola::front(){
    return header->next->SuPedido;
}

void cola::enqueue(const pedidos & dt){
    if(tam < tamMax){
        Node *nd = new Node;
        nd->SuPedido = dt;
        nd->next = trailer;
        nd->prev = trailer->prev;

        trailer->prev->next = nd;
        trailer->prev = nd;
        tam++;
    }
}

void cola::dequeue(){
    if(!empty()){
        Node *nd = header->next->next;

        delete header->next;
        header->next = nd;
        nd->prev = header;

        tam--;
    }
}

bool cola::empty() const{
    return(tam == 0);
}

int cola::size() const{
    return tam;
}


int main() {

    bodega b1(4);
    b1.push(8, 2, 6, "arroz");
    b1.push(10, 4, 4, "cerveza");
    b1.push(8, 6, 5, "cereal");
    b1.push(6, 5, 2, "avena");
    b1.pop();

    cout << b1.top() << " " << b1.size() << endl;
    cout << b1.empty() << endl;


    pedidos pedidosPendientes[3] ={
        {.producto = {"Arroz","Pan"},.cantidad= {10,5}, .numeroPedido = 2, .estado = false},
        {.producto ={"Cerveza","Arroz"},.cantidad={20,10}, .numeroPedido = 5, .estado = false},
        {.producto = {"Pan","Cerveza"},.cantidad={30,5}, .numeroPedido = 7, .estado = false}
        };


    cola c1(3);
    c1.enqueue(pedidosPendientes[0]);
    c1.enqueue(pedidosPendientes[1]);
    c1.enqueue(pedidosPendientes[2]);
    c1.dequeue();

    cout << c1.size() << endl;





    return 0;

}


