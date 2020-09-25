#ifndef _TEST_BUSQUEDA
#define _TEST_BUSQUEDA

#include <vector>
#include "AlgoritmosBusqueda.h"
#include "Mtime.h"
#include "AlgoritmosOrdenacion.h"
#include "vectorInt.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

class TestBusqueda{
	vector<string> nombreAlgoritmo;
public:

	TestBusqueda();
	~TestBusqueda();

	static double buscaEnArrayDeInt(vector<int> &v, int metodo, int key, int &posicion);

	void comprobarMetodosBusqueda();

	void casoMedio(int metodo);

	void comparar(int metodo1, int metodo2);

	//NO PEDIDO PRACTICAS
	void compararTodos();
};
#endif