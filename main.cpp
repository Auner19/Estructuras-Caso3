#include "bodega.h"
#include "pedidos.h"

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


    return 0;

}


