#include <iostream>
#include "grafo.h"
#define NO_VISITADO 0
#define VISITADO 1

using namespace std;
void inicializar(int * visitado,int tam)
{
    for(int x= 1;x<=tam;x++)
        visitado[x]=NO_VISITADO;
    }
void BFS(Grafo<int> g,int vertice,int * visitado)
{
    list<Grafo<int>::Arco> adyacentes;
    list<int> fila;
    list<Grafo<int>::Arco>::const_iterator it_fila;
    list<Grafo<int>::Arco>::const_iterator ad;
    visitado[vertice]=VISITADO;
    fila.push_back(vertice);
    while (!fila.empty()){
        int aux = fila.front();
        fila.remove(aux);
        g.devolverAdyacentes(aux,adyacentes);
        for(ad=adyacentes.begin();ad!=adyacentes.end();ad++)
            if (visitado[ad->devolverAdyacente()]==NO_VISITADO){
                cout<<" -> "<<ad->devolverAdyacente();
                visitado[ad->devolverAdyacente()]=VISITADO;
                fila.push_back(ad->devolverAdyacente());
            }
    }

}
void BFS_FOREST(Grafo<int> g)
{
    int visitado[g.devolverLongitud()];
    inicializar(visitado,g.devolverLongitud());
    list<int> vertices;
    list<int>::const_iterator it;
    g.devolverVertices(vertices);
    for(it=vertices.begin();it!=vertices.end();it++)
        if (visitado[*it]==NO_VISITADO){
            cout<<*it;
            BFS(g,*it,visitado);
            }
}
int main()
{
    Grafo<int> grafo1;
    grafo1.agregarVertice(1);
	grafo1.agregarVertice(2);
	grafo1.agregarVertice(3);
	grafo1.agregarVertice(4);
	grafo1.agregarVertice(5);
	grafo1.agregarVertice(6);
	grafo1.agregarVertice(7);
	grafo1.agregarVertice(8);
	grafo1.agregarArco(1, 2, 11);
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
	BFS_FOREST(grafo1);

}
