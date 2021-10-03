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
        arrayDeStacks[contador].producto = pInventario[indiceArray].producto;
        contador++;
        }   
    }
}

void imprimirBodega(){

    for (int indice = 0; indice <5; indice++)
    {
        cout << arrayDeStacks[indice].size() << endl;
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

void completarPedidos(Montacargas pArray[], Bodega pInventario[], int sizeArrayMontacargas, int sizeArrayStacks){

    for (int indiceMontacargas = 0; indiceMontacargas < sizeArrayMontacargas; indiceMontacargas++) 
    {
        while(!pArray[indiceMontacargas].colaMontacarga.empty()) 
        {
            int cantidadProducto = pArray[indiceMontacargas].colaMontacarga.front().cantidad; 

            while (cantidadProducto > 0) 
            {
                for ( int i = 0; i < sizeArrayStacks; i++) 
                {
                    if (arrayDeStacks[i].producto == pArray[indiceMontacargas].colaMontacarga.front().producto && cantidadProducto!= 0)
                        {
                            while(cantidadProducto>0)
                            {
                                cantidadProducto -= arrayDeStacks[i].top();
                                arrayDeStacks[i].pop(); 
                            }
                        }
                    pArray[i].colaMontacarga.front().estado = true;
                    
                }
            }
            pArray[indiceMontacargas].colaMontacarga.dequeue(); 
         }
    }          
}
int main(){

    Pedidos pedidosPendientes[2]; 

    pedidosPendientes[0].cantidad = 90;
    pedidosPendientes[0].producto = "Arroz";
    pedidosPendientes[0].numeroPedido = 10;
    pedidosPendientes[0].estado = false;

    pedidosPendientes[1].cantidad = 50;
    pedidosPendientes[1].producto = "Cerveza";
    pedidosPendientes[1].numeroPedido = 5;
    pedidosPendientes[1].estado = false;

    Bodega inventario[2];

    inventario[0].columnas = 2;
    inventario[0].paletasXcolumna = 5;
    inventario[0].unidadesXpaletas = 30;
    inventario[0].producto = "Arroz";

    inventario[1].columnas = 3;
    inventario[1].paletasXcolumna = 3;
    inventario[1].unidadesXpaletas = 25;
    inventario[1].producto = "Cerveza";
        

    Montacargas montacargasActivos[2];

    crearBodega(inventario);
    crearMontacargas(2,2,montacargasActivos,pedidosPendientes);
    imprimirBodega();
    completarPedidos(montacargasActivos,inventario,2,5);

    cout << "------------------" << endl;

    imprimirBodega();
}


