#ifndef _TEST_ORDENACION
#define _TEST_ORDENACION

#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <iostream>

#include "AlgoritmosOrdenacion.h"
#include "vectorInt.h"

using namespace std;

class TestOrdenacion {
	vector<string> nombreAlgoritmo;
public:

	TestOrdenacion();
	~TestOrdenacion();
	
	static double ordenarArrayDeInt(vector<int> &v, int metodo);

	void comprobarMetodosOrdenacion();

	void comparar(int metodo1, int metodo2);

	void casoMedio(int metodo);

	//NO PEDIDO PRACTICAS
	void compararTodos();
};
#endif