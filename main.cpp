#include <iostream>
#include <string>
#include "cstdlib"

#include "pila.h"
#include "cola.h"
#include "bodega.h"
#include "pedidos.h"
#include "montacargas.h"

using namespace std;

Stack arrayDeStacks[10];

void crearBodega(Bodega pInventario[], int sizeInventario){

    int contador = 0;

    for (int indiceArray = 0; indiceArray < sizeInventario; indiceArray++)
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

    for (int indice = 0; indice <10; indice++)
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

                for ( int i = 0; i < sizeArrayStacks; i++) 
                {
                    if (arrayDeStacks[i].producto == pArray[indiceMontacargas].colaMontacarga.front().producto && cantidadProducto!= 0)
                        {
                            while(cantidadProducto>0 && !arrayDeStacks[i].empty())
                            {
                                cantidadProducto -= arrayDeStacks[i].top();
                                arrayDeStacks[i].pop();

                                if (cantidadProducto < 0){
                                    arrayDeStacks[i].push(cantidadProducto*-1);
                                }
                            }
                        }
                } 
            if (cantidadProducto <= 0){
                    pArray[indiceMontacargas].colaMontacarga.front().estado = true;
                    cout << "Estado del pedido " << pArray[indiceMontacargas].colaMontacarga.front().numeroPedido <<": "<< pArray[indiceMontacargas].colaMontacarga.front().estado << endl;
                }
            else{
                cout << "Estado del pedido " << pArray[indiceMontacargas].colaMontacarga.front().numeroPedido <<": "<< pArray[indiceMontacargas].colaMontacarga.front().estado << endl;
                
                }
            pArray[indiceMontacargas].colaMontacarga.dequeue(); 
         }
    }          
}

int main(){

    Pedidos pedidosPendientes[3]; 

    pedidosPendientes[0].cantidad = 100;
    pedidosPendientes[0].producto = "Arroz";
    pedidosPendientes[0].numeroPedido = 10;
    pedidosPendientes[0].estado = false;

    pedidosPendientes[1].cantidad = 200;
    pedidosPendientes[1].producto = "Cerveza";
    pedidosPendientes[1].numeroPedido = 5;
    pedidosPendientes[1].estado = false;

    pedidosPendientes[2].cantidad = 1000;
    pedidosPendientes[2].producto = "Manzanas";
    pedidosPendientes[2].numeroPedido = 7;
    pedidosPendientes[2].estado = false;

    Bodega inventario[3];

    inventario[0].columnas = 2;
    inventario[0].paletasXcolumna = 5;
    inventario[0].unidadesXpaletas = 500;
    inventario[0].producto = "Arroz";

    inventario[1].columnas = 3;
    inventario[1].paletasXcolumna = 3;
    inventario[1].unidadesXpaletas = 40; 
    inventario[1].producto = "Cerveza";

    inventario[2].columnas = 5;
    inventario[2].paletasXcolumna = 4;
    inventario[2].unidadesXpaletas = 25; 
    inventario[2].producto = "Manzanas";
        

    Montacargas montacargasActivos[2];

    crearBodega(inventario,3);

    imprimirBodega();

    cout << "----------------" << endl;

    crearMontacargas(3,2,montacargasActivos,pedidosPendientes);
    
    verMontacargas(2,montacargasActivos);

    cout << "----------------" << endl;

    completarPedidos(montacargasActivos, inventario,2,10);


}
