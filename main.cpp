#include <iostream>
#include <string>

#include "pedidos.h"
#include "bodega.h"
#include "montacargas.h"

using namespace std;

void imprimirInventario(Bodega pInventario[]){

    cout << "----Inventario de la bodega---- \n" << endl;

    for (int i = 0; i < 3; i++)
        {
            cout << "Producto: " << pInventario[i].producto << endl;
            cout << "Columnas: " << pInventario[i].columnas << endl;
            cout << "Paletas: " << pInventario[i].paletasXcolumna << endl;
            cout << "Unidades: " << pInventario[i].unidadesXpaletas << "\n" << endl;      
        }
};

void imprimirPedidos(Pedidos pPedidos[]){

    cout << "----Pedidos Pendientes---- " << endl;
    for (int i = 0; i < 3; i++){

    cout << "\nNúmero de pedido: " << pPedidos[i].numeroPedido << endl;
    cout << "Estado del pedido: " << pPedidos[i].estado << endl;
    cout << "Productos / Unidades: \n " << endl;

            for (int j = 0; j < 2; j++)
            {
            cout << pPedidos[i].producto[j] << " , " << pPedidos[i].cantidad[j] << endl;
            }
        }
};

void imprimirMontacargas(Montacargas pMontacargas){

    cout << "\n----Montacargas---- \n" << endl;
    cout << "Disponibles: " << pMontacargas.montacargasDisponibles << endl;
    cout << "Tiempo de trabajo: " << pMontacargas.duracionProceso << "ms" << endl;

};

int main(){

    Pedidos pedidosPendientes[3] ={
        {.producto = {"Arroz","Pan"},.cantidad= {10,5}, .numeroPedido = 2, .estado = false},
        {.producto ={"Cerveza","Arroz"},.cantidad={20,10}, .numeroPedido = 5, .estado = false},
        {.producto = {"Pan","Cerveza"},.cantidad={30,5}, .numeroPedido = 7, .estado = false}
        };

    Bodega inventario[3] = { 
        {.columnas=2, .paletasXcolumna=1, .unidadesXpaletas=30, .producto="Arroz"},
        {.columnas=3, .paletasXcolumna=2, .unidadesXpaletas=40, .producto="Cerveza"},
        {.columnas=4, .paletasXcolumna=3, .unidadesXpaletas=50, .producto="Pan"}
        };

    Montacargas montacargasActivos;

    montacargasActivos.duracionProceso = 400;
    montacargasActivos.montacargasDisponibles = 7;

    imprimirInventario(inventario);
    imprimirPedidos(pedidosPendientes);
    imprimirMontacargas(montacargasActivos);

    return 0;
}









