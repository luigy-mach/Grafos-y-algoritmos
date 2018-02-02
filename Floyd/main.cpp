#include <iostream>
#include "Grafo.h"
#include <windows.h>
//-----------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------//
void cargar_grafo(Grafo<int> &grafo)
{
    grafo.agregarVertice(0);
    grafo.agregarVertice(1);
    grafo.agregarVertice(2);
    grafo.agregarVertice(3);
    grafo.agregarVertice(4);
    grafo.agregarVertice(5);
    grafo.agregarArco(0,5,28);
    grafo.agregarArco(5,0,28);
    grafo.agregarArco(0,1,24);
    grafo.agregarArco(1,0,24);
    grafo.agregarArco(1,2,11);
    grafo.agregarArco(2,1,11);
    grafo.agregarArco(2,3,13);
    grafo.agregarArco(3,2,13);
    grafo.agregarArco(3,4,20);
    grafo.agregarArco(4,3,20);
    grafo.agregarArco(3,5,12);
    grafo.agregarArco(5,3,12);
    grafo.agregarArco(4,5,15);
    grafo.agregarArco(5,4,15);
}
//-----------------------------------------------------------------//
void mostrar_matriz(int ** mat_costos,int max)
{
    //muestra la matriz de costos
    for (int fila = 0; fila < max; fila++)
    {
        for(int columna = 0; columna < max; columna++)
            cout << "[" << mat_costos[columna][fila] << "]";
        cout << endl;
    }
}
//-----------------------------------------------------------------//
void inicializar(int ** & mat_costos,Grafo<int> grafo)
{
    //inicializa la matriz de costos con los costo de cada arco
    mat_costos = new int * [grafo.devolverLongitud()];
    for (int x = 0; x < grafo.devolverLongitud(); x++)
        mat_costos[x] = new int [grafo.devolverLongitud()];
    for (int fila = 0; fila < grafo.devolverLongitud(); fila++)
        for(int columna = 0; columna < grafo.devolverLongitud(); columna++)
            mat_costos[columna][fila] = grafo.costoArco(columna, fila);
    for(int fil_col = 0; fil_col < grafo.devolverLongitud(); fil_col++)
        mat_costos[fil_col][fil_col] = 0;

}
//-----------------------------------------------------------------//
void floyd(int ** mat_costo, int longitud)
{
    for (int k = 0; k < longitud; k++)
        for(int vert = 0; vert < longitud; vert++)
            for(int vert2 = 0; vert2 < longitud; vert2++)
                if (mat_costo[vert][k] + mat_costo[k][vert2] < mat_costo[vert][vert2])
                    mat_costo[vert][vert2] = mat_costo[vert][k] + mat_costo[k][vert2];
}
//-----------------------------------------------------------------//
int main()
{
    Grafo<int> grafo; //grafo principal
    cargar_grafo(grafo);
    int ** mat_costos; //matriz de costos
    inicializar(mat_costos,grafo);
    cout << "ATENCION: El valor Infinito es: " << infinito;
    cout << endl << endl << "Matriz de Costos Original" << endl;
    mostrar_matriz(mat_costos, grafo.devolverLongitud());
    floyd(mat_costos, grafo.devolverLongitud());
    cout << endl << "Matriz de Costos Minimos" << endl;
    mostrar_matriz(mat_costos, grafo.devolverLongitud());
}
