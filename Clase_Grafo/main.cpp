#include "Grafo.h"
#include "iostream"
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
int main(int argc, char **argv)
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
	cout << grafo1 << endl;
}

