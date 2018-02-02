#include <iostream>
#include "Grafo.h"
#define no_visitado 0
#define visitado 1
//------------------------------------------------------------------//
using namespace std;
//------------------------------------------------------------------//
void cargar_grafo(Grafo<int> &grafo1)
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
	grafo1.agregarArco(4, 7, 4);
	grafo1.agregarArco(6, 8, 4);
	grafo1.agregarArco(5, 8, 5);
	grafo1.agregarArco(5, 4, 10);
	grafo1.agregarArco(7, 8, 17);
	cout << grafo1 << endl;
}
//------------------------------------------------------------------//
void DFS_visitar(Grafo<int> grafo1, int iterador_vertices, int marca_visitados[], list<int> &orden_topologico)
{
    marca_visitados[iterador_vertices] = visitado;
    list<Grafo<int>::Arco> adyacentes;
    grafo1.devolverAdyacentes(iterador_vertices, adyacentes);
    list<Grafo<int>::Arco>::const_iterator iterador_adyacentes;
    for(iterador_adyacentes = adyacentes.begin(); iterador_adyacentes != adyacentes.end(); iterador_adyacentes++)
        if (marca_visitados[iterador_adyacentes->devolverAdyacente()] == no_visitado)
        {
            DFS_visitar(grafo1, iterador_adyacentes->devolverAdyacente(), marca_visitados, orden_topologico);
            orden_topologico.push_front(iterador_adyacentes->devolverAdyacente());  
        }
}
//------------------------------------------------------------------//
int main()
{
    Grafo<int> grafo1;
    cargar_grafo(grafo1);
    list<int> vertices;
    grafo1.devolverVertices(vertices);
    list<int>::const_iterator iterador_vertices;
    int marca_visitados[vertices.size()];
    list<int> orden_topologico;
    for(iterador_vertices = vertices.begin(); iterador_vertices != vertices.end(); iterador_vertices++)
        marca_visitados[*iterador_vertices] = no_visitado;
    for(iterador_vertices = vertices.begin(); iterador_vertices != vertices.end(); iterador_vertices++)
        if (marca_visitados[*iterador_vertices] == no_visitado)
        {
            DFS_visitar(grafo1, *iterador_vertices, marca_visitados, orden_topologico);
            orden_topologico.push_front(*iterador_vertices);
        }
    list<int>::const_iterator iterador_topologico = orden_topologico.begin();
    while (iterador_topologico != orden_topologico.end())
    {
        cout << " " << *iterador_topologico;
        iterador_topologico++;
    }
}
//------------------------------------------------------------------//