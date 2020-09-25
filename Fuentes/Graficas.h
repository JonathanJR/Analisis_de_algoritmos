#ifndef _GRAFICA
#define _GRAFICA
#include <string>
#include <iostream>
using namespace std;

class Graficas{
public:
	void generarGraficaMEDIO(string metodo, int orden);
	void generarGraficaCMP(string metodo1, string metodo2);

	//NO PEDIDO PRACTICAS
	void generarGraficaCMP2(string metodo1, string metodo2, string metodo3, string metodo4, string metodo5, string nombre6, string nombre7);
	void generarGraficaCMP3(string metodo1, string metodo2, string metodo3, string nombre4);
};
#endif