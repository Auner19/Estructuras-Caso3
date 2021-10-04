#include <iostream>
#include <string>
#include "cstdlib"

#include "pila.h"
#include "cola.h"
#include "bodega.h"
#include "pedidos.h"
#include "montacargas.h"

using namespace std;

Stack arrayDeStacks[11]; //Se crea el array de pilas

int duracionProceso = 10;

void crearBodega(Bodega pInventario[], int pSizeInventario){ // Se crea la bodega mendiante el push
    int indiceArrayStack = 0;
    for (int indiceArrayInventario = 0; indiceArrayInventario < pSizeInventario; indiceArrayInventario++){
        for (int columna = 0; columna < pInventario[indiceArrayInventario].columnas; columna++){
            for (int paleta = 0; paleta < pInventario[indiceArrayInventario].paletasXcolumna; paleta++){    
                arrayDeStacks[indiceArrayStack].push(pInventario[indiceArrayInventario].unidadesXpaletas);
            }
         arrayDeStacks[indiceArrayStack].producto = pInventario[indiceArrayInventario].producto;
         indiceArrayStack++;
        }   
    }
}

void imprimirBodega(int pSizeArrayStacks){  //Imprime la cantidad de elemento de cada pila de la bodega
    for (int indiceArrayStacks = 0; indiceArrayStacks <pSizeArrayStacks; indiceArrayStacks++){
        cout << arrayDeStacks[indiceArrayStacks].size() << endl;
    }   
}


//Distribuye los pedidos entre los montacargas(no selecciona pedidos de forma aleatoria)
void crearMontacargas(int pCantidadPedidos, int pCantidadMontacargas, Montacargas pArrayMontacargas[], Pedidos pPendientes[]){
    int indicePedido = 0;
    int indiceMontacarga = 0;
    while (indicePedido < pCantidadPedidos){
        if(indiceMontacarga == pCantidadMontacargas){
            indiceMontacarga = 0;
        }
        pArrayMontacargas[indiceMontacarga].colaMontacarga.enqueue(pPendientes[indicePedido]);
        indicePedido++;
        indiceMontacarga++;
    }
}

void verMontacargas(int pSizeArregloMontacarga , Montacargas pArrayMontacargas[]){ //Imprime la cantidad de pedidos de cada montacarga
    for (int indice = 0; indice < pSizeArregloMontacarga; indice++){
        cout << pArrayMontacargas[indice].colaMontacarga.size() << endl;
    }
}

//Completa los pedidos
void completarPedidos(Montacargas pArrayMontacargas[], int pSizeArrayMontacargas, int pSizeArrayStacks){
    for (int indiceMontacargas = 0; indiceMontacargas < pSizeArrayMontacargas; indiceMontacargas++) {
        int tiempoTotal = 0;
        while(!pArrayMontacargas[indiceMontacargas].colaMontacarga.empty()) {
            int cantidadProducto = pArrayMontacargas[indiceMontacargas].colaMontacarga.front().cantidad;
            for (int indiceArrayStacks = 0; indiceArrayStacks < pSizeArrayStacks; indiceArrayStacks++){
                    if (arrayDeStacks[indiceArrayStacks].producto == pArrayMontacargas[indiceMontacargas].colaMontacarga.front().producto && cantidadProducto!= 0){
                        while(cantidadProducto>0 && !arrayDeStacks[indiceArrayStacks].empty()){
                            cantidadProducto -= arrayDeStacks[indiceArrayStacks].top();
                            arrayDeStacks[indiceArrayStacks].pop();
                            tiempoTotal += duracionProceso;

                         if (cantidadProducto < 0){
                             arrayDeStacks[indiceArrayStacks].push(cantidadProducto*-1);
                             tiempoTotal += duracionProceso;

                            }
                        }
                    }
            }
            if (cantidadProducto <= 0){
                pArrayMontacargas[indiceMontacargas].colaMontacarga.front().estado = true;
                cout << "Estado del pedido " << pArrayMontacargas[indiceMontacargas].colaMontacarga.front().numeroPedido 
                << ": "<< pArrayMontacargas[indiceMontacargas].colaMontacarga.front().estado << " / Duracion pedido: " 
                << tiempoTotal << " milisegundos" << endl;
            }
            else{
                cout << "Estado del pedido " << pArrayMontacargas[indiceMontacargas].colaMontacarga.front().numeroPedido 
                <<": "<< pArrayMontacargas[indiceMontacargas].colaMontacarga.front().estado << 
                " / No se completo el pedido en su totalidad" << endl;
            }
            pArrayMontacargas[indiceMontacargas].colaMontacarga.dequeue(); 
        }
    }          
}

int main(){

    Pedidos pedidosPendientes[6]; // Se crea el array de pedidos (los pedidos solo reciben 1 producto por el momento)

    pedidosPendientes[0].cantidad = 95;
    pedidosPendientes[0].producto = "Arroz";
    pedidosPendientes[0].numeroPedido = 10;
    pedidosPendientes[0].estado = false;

    pedidosPendientes[1].cantidad = 5;
    pedidosPendientes[1].producto = "Arroz";
    pedidosPendientes[1].numeroPedido = 15;
    pedidosPendientes[1].estado = false;

    pedidosPendientes[2].cantidad = 200;
    pedidosPendientes[2].producto = "Cerveza";
    pedidosPendientes[2].numeroPedido = 27;
    pedidosPendientes[2].estado = false;

    pedidosPendientes[3].cantidad = 10;
    pedidosPendientes[3].producto = "Cerveza";
    pedidosPendientes[3].numeroPedido = 45;
    pedidosPendientes[3].estado = false;

    pedidosPendientes[4].cantidad = 751;
    pedidosPendientes[4].producto = "Manzanas";
    pedidosPendientes[4].numeroPedido = 32;
    pedidosPendientes[4].estado = false;

    pedidosPendientes[5].cantidad = 750;
    pedidosPendientes[5].producto = "Manzanas";
    pedidosPendientes[5].numeroPedido = 14;
    pedidosPendientes[5].estado = false;

    Bodega inventario[3]; // Se crea el array de bodega 

    inventario[0].columnas = 2;
    inventario[0].paletasXcolumna = 5;
    inventario[0].unidadesXpaletas = 10;
    inventario[0].producto = "Arroz";

    inventario[1].columnas = 4;
    inventario[1].paletasXcolumna = 2;
    inventario[1].unidadesXpaletas = 25; 
    inventario[1].producto = "Cerveza";

    inventario[2].columnas = 5;
    inventario[2].paletasXcolumna = 3;
    inventario[2].unidadesXpaletas = 100; 
    inventario[2].producto = "Manzanas";
        
    Montacargas montacargasActivos[2];

    crearBodega(inventario,3);
    //imprimirBodega(11);
    //cout << "----------------" << endl;

    crearMontacargas(6,2,montacargasActivos,pedidosPendientes);
    //verMontacargas(2,montacargasActivos);
    //cout << "----------------" << endl;
    
    completarPedidos(montacargasActivos,2,11);

}
