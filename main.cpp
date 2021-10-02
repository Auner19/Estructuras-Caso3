#include <iostream>
#include <string>
#include "cstdlib"

#include "pila.h"
#include "cola.h"
#include "bodega.h"
#include "pedidos.h"
#include "montacargas.h"

using namespace std;

Stack arrayDeStacks[5];

void crearBodega(Bodega pInventario[]){

    int contador = 0;

    for (int indiceArray = 0; indiceArray < 2; indiceArray++)
    {
        for (int columna = 0; columna < pInventario[indiceArray].columnas; columna++)
        {
            for (int paleta = 0; paleta < pInventario[indiceArray].paletasXcolumna; paleta++)
            {    
                arrayDeStacks[contador].push(pInventario[indiceArray].unidadesXpaletas);
            } 
        contador++;
        }   
    }
}

void imprimirBodega(){

    for (int indice = 0; indice <5; indice++)
    {
        cout << "Indice del Array: " << indice << endl;

        int stackSize = arrayDeStacks[indice].size();
        
        for (int subindice = 0; subindice < stackSize; subindice++)
        {
            arrayDeStacks[indice].top();
            arrayDeStacks[indice].pop();
        }
    }   
}

void crearMontacargas(int cantidadPedidos, int cantidadMontacargas, Montacargas arrayMontacargas[],Pedidos pPendientes[]){

    int indicePedido = 0;
    int indiceMontacarga = 0;

        while (indicePedido < cantidadPedidos)
        {
            if(indiceMontacarga==cantidadMontacargas){
                indiceMontacarga = 0;
            }
            arrayMontacargas[indiceMontacarga].colaMontacarga.enqueue(pPendientes[indicePedido]);
            indicePedido++;
            indiceMontacarga++;
        }
}

void verMontacargas(int sizeArreglo , Montacargas arrayMontacargas[]){

    for (int i = 0; i < sizeArreglo; i++)
    {
        cout << arrayMontacargas[i].colaMontacarga.size() << endl;
    }
}

int main() {

    Pedidos pedidosPendientes[6] ={
        {.producto = {"Arroz","Pan"},.cantidad= {10,5}, .numeroPedido = 2, .estado = false},
        {.producto ={"Cerveza","Arroz"},.cantidad={20,10}, .numeroPedido = 5, .estado = false},
        {.producto = {"Pan","Cerveza"},.cantidad={30,5}, .numeroPedido = 7, .estado = false},
        {.producto = {"Arroz","Pan"},.cantidad= {10,5}, .numeroPedido = 2, .estado = false},
        {.producto ={"Cerveza","Arroz"},.cantidad={20,10}, .numeroPedido = 5, .estado = false},
        {.producto = {"Pan","Cerveza"},.cantidad={30,5}, .numeroPedido = 7, .estado = false},
        };

    Bodega inventario[2] = {
        {.columnas=2, .paletasXcolumna=5, .unidadesXpaletas=30, .producto="Arroz"},
        {.columnas=3, .paletasXcolumna=3, .unidadesXpaletas=100, .producto="Cerveza"}
        };

    Montacargas montacargasActivos[3];

    crearBodega(inventario);
    imprimirBodega();
    crearMontacargas(6,3,montacargasActivos,pedidosPendientes);
    verMontacargas(3,montacargasActivos);

    

} 

