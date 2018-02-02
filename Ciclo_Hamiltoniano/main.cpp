#include <iostream>
#include "Grafo.h"
#define no_visitado 0
#define esta_visitado 1
//---------------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------------
void cargar_grafo(Grafo<int> &grafo1)
{
    grafo1.agregarVertice(1);
    grafo1.agregarVertice(2);
    grafo1.agregarVertice(3);
    grafo1.agregarVertice(4);
    grafo1.agregarVertice(5);
    grafo1.agregarVertice(6);
    grafo1.agregarArco(1,5,13);
    grafo1.agregarArco(5,4,13);
    grafo1.agregarArco(5,6,13);
    grafo1.agregarArco(6,3,13);
    grafo1.agregarArco(3,2,13);
   // grafo1.agregarArco(2,1,13);
    grafo1.agregarArco(4,1,13);
    grafo1.agregarArco(4,6,13);
    cout << grafo1 << endl;
}
//---------------------------------------------------------------------------------
bool todos_visitados(bool visitado[], int tam_vertice)
{
    for(int i = 1; i <= tam_vertice; i++)
        if(visitado[i] == no_visitado)
            return false;
    return true;
}
//---------------------------------------------------------------------------------
bool hay_ciclo_hamiltoniano(Grafo<int> grafo1, int vertice, bool visitado[], int primero, int tam_vertice)
{
    visitado[vertice] = esta_visitado;
    list<Grafo<int>::Arco> adyacentes;
    grafo1.devolverAdyacentes(vertice, adyacentes);
    list<Grafo<int>::Arco>::const_iterator iterador_adyacente;
    bool found = false;
    for(iterador_adyacente = adyacentes.begin(); ((iterador_adyacente != adyacentes.end())&&(found == false)); iterador_adyacente++)
        if(visitado[iterador_adyacente->devolverAdyacente()] == no_visitado)
        {
            found = hay_ciclo_hamiltoniano(grafo1, iterador_adyacente->devolverAdyacente(), visitado, primero, tam_vertice);
            //visitado[iterador_adyacente->devolverAdyacente()] = no_visitado;
        }
        else
            if(iterador_adyacente->devolverAdyacente() == primero)
                found = todos_visitados(visitado, tam_vertice);
    return found;
}
//---------------------------------------------------------------------------------
int main()
{
    Grafo<int> grafo1;
    cargar_grafo(grafo1);
    list<int> vertices;
    grafo1.devolverVertices(vertices);
    list<int>::const_iterator iterador_vertice;
    iterador_vertice = vertices.begin();
    bool hay_ciclo = false;
    bool visitado[vertices.size()];
    for (int i = 1; i <= vertices.size(); i++)
        visitado[i] = no_visitado;
    int tam_vertice = vertices.size();
    hay_ciclo = hay_ciclo_hamiltoniano(grafo1, *iterador_vertice, visitado, *iterador_vertice, tam_vertice);
    if (hay_ciclo == false)
        cout << endl << "No hay ciclo hamiltoniano" << endl;
    else
        cout << endl << "Hay ciclo hamiltoniano" << endl;
    return 0;
}
//---------------------------------------------------------------------------------