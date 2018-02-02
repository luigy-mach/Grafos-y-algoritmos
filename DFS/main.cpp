#include <iostream>
#include "Grafo.h"
#define no_visitado 0
#define visitado 1
//---------------------------------------------------------------//
using namespace std;
//--------------------------- DFS -------------------------------//
void cargar_grafo(Grafo<int> & grafo1)
{
    grafo1.agregarVertice(1);
	grafo1.agregarVertice(2);
	grafo1.agregarVertice(3);
	grafo1.agregarVertice(4);
	grafo1.agregarVertice(5);
	grafo1.agregarVertice(6);
	grafo1.agregarVertice(7);
	grafo1.agregarVertice(8);
	grafo1.agregarArco(1, 2, 11); // parametros: (vertice 1, vertice 2, costo arco)
	grafo1.agregarArco(1, 7, 9);
	grafo1.agregarArco(1, 4, 23);
	grafo1.agregarArco(2, 6, 14);
	grafo1.agregarArco(3, 5, 3);
	grafo1.agregarArco(4, 2, 5);
	grafo1.agregarArco(4, 7, 4);
	grafo1.agregarArco(5, 6, 5);
	grafo1.agregarArco(5, 4, 10);
	grafo1.agregarArco(7, 3, 21);
	grafo1.agregarArco(7, 8, 17);
}
//---------------------------------------------------------------//
void DFS_visitar(int iterador_vertices, int *marca_visitado, Grafo<int> grafo1)
{
    marca_visitado[iterador_vertices] = visitado;
    list<Grafo<int>::Arco> adyacentes;
    grafo1.devolverAdyacentes(iterador_vertices, adyacentes);
    list<Grafo<int>::Arco>::const_iterator iterador_adyacentes;
    iterador_adyacentes = adyacentes.begin();
    while(iterador_adyacentes != adyacentes.end())
    {
      if(marca_visitado[iterador_adyacentes->devolverAdyacente()] == no_visitado)
      {
        cout << iterador_adyacentes->devolverAdyacente() << " ";
        DFS_visitar(iterador_adyacentes->devolverAdyacente(), marca_visitado, grafo1);
      }
      iterador_adyacentes++;
    }
}
//---------------------------------------------------------------//
int main()
{
    Grafo<int> grafo1;
    cargar_grafo(grafo1);
    list<int> vertices;
    grafo1.devolverVertices(vertices);
    list<int>::const_iterator iterador_vertices;
    iterador_vertices = vertices.begin();
    int marca_visitado[vertices.size()];
    while (iterador_vertices != vertices.end())
    {
        marca_visitado[*iterador_vertices] = no_visitado;
        iterador_vertices++;
    }
    iterador_vertices = vertices.begin();
    cout << grafo1 << endl << "Recorrido del DFS" << endl << endl;
    while (iterador_vertices != vertices.end())
    {
      if (marca_visitado[*iterador_vertices] == no_visitado)
      {
        cout << *iterador_vertices << " ";
        DFS_visitar(*iterador_vertices, marca_visitado, grafo1);
      }
      iterador_vertices++;
    }
    cout << endl;
}
//---------------------------------------------------------------//