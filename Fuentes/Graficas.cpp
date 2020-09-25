#include "Graficas.h"
#include "Constantes.h"
#include <fstream>
#include <iostream>
using namespace std;


void Graficas::generarGraficaMEDIO(string nombre_metodo, int orden)
{
	ofstream fin("medioGrafica.plt");
	fin << "set title \"" << nombre_metodo << "\"\n";
	fin << "set key top left vertical inside\n";
	fin << "set grid\n";
	fin << "set xlabel \"Talla (n)\"\n";
	fin << "set ylabel \"Tiempo (ms)\"\n";

	switch (orden) {
	case CUADRADO: {
		fin << "Cuadrado(x) = a*x**2 + b*x + c\n";
		fin << "fit Cuadrado(x) \"" << nombre_metodo << ".dat\" using 1:2 via a,b,c\n";
		fin << "plot \"" << nombre_metodo << ".dat\" using 1:2  title \"" << nombre_metodo << "\" , Cuadrado(x)\n";
	}
				   break;
	case NlogN: {
		fin << "LogaritmicoN(x) = a*x*log(x) + b*x + c\n";
		fin << "fit LogaritmicoN(x) \"" << nombre_metodo << ".dat\" using 1:2 via a,b,c\n";
		fin << "plot \"" << nombre_metodo << ".dat\" using 1:2  title \"" << nombre_metodo << "\" , LogaritmicoN(x)\n";
	}
				break;
	case logN: {
		fin << "Logaritmico(x) = a*log(x) + b\n";
		fin << "fit Logaritmico(x) \"" << nombre_metodo << ".dat\" using 1:2 via a,b\n";
		fin << "plot \"" << nombre_metodo << ".dat\" using 1:2  title \"" << nombre_metodo << "\" , Logaritmico(x)\n";
	}
			   break;
	case N: {
		fin << "Lineal(x) = a*x + b\n";
		fin << "fit Lineal(x) \"" << nombre_metodo << ".dat\" using 1:2 via a,b\n";
		fin << "plot \"" << nombre_metodo << ".dat\" using 1:2  title \"" << nombre_metodo << "\" , Lineal(x)\n";
	}
			break;
	case OSHELL: {
		fin << "OrdenShell(x) = a*x**(3/2) + b*x + c\n";
		fin << "fit OrdenShell(x) \"" << nombre_metodo << ".dat\" using 1:2 via a,b,c\n";
		fin << "plot \"" << nombre_metodo << ".dat\" using 1:2  title \"" << nombre_metodo << "\" , OrdenShell(x)\n";
	}
				 break;

	default: {}
	}
	fin << "set terminal pdf\n";
	fin << "set output \"" << nombre_metodo << ".pdf\" \n";
	fin << "replot\n";
	fin << "pause 5\"Pulsa Enter para continuar...\"";
	fin.close();
}

void  Graficas::generarGraficaCMP(string nombre1, string nombre2)
{
	string orden = "";
	ofstream fin("comparaDosGraficas.plt");
	fin << "set title \"" << nombre1 << " y " << nombre2 << "\"\n";
	fin << "set key top left vertical inside\n";
	fin << "set grid\n";
	fin << "set xlabel \"Talla (n)\"\n";
	fin << "set ylabel \"Tiempo (ms)\"\n";
	fin << "plot \"" << nombre1 << ".dat\" using 1:2 with lines title \"" << nombre1 << "\" , \"" << nombre2 << ".dat\" using 1:2 with lines title \"" << nombre2 << "\"\n";
	fin << "set terminal pdf\n";
	fin << "set output\"" << nombre1 << nombre2 << ".pdf\" \n";
	fin << "replot\n";
	fin << "pause 5\"Pulsa Enter para continuar...\"";
	fin.close();
}

// NO PEDIDO EN PRACTICA //

void  Graficas::generarGraficaCMP2(string nombre1, string nombre2, string nombre3, string nombre4, string nombre5, string nombre6, string nombre7)
{
	ofstream fin("comparaTodosGraficas.plt");
	fin << "set title \"" << nombre1 << " , " << nombre2 << " , " << nombre3 << " , " << nombre4 << " , " << nombre5 << " , " << nombre6 << " y " << nombre7 << "\"\n";
	fin << "set key top left vertical inside\n";
	fin << "set grid\n";
	fin << "set xlabel \"Talla (n)\"\n";
	fin << "set ylabel \"Tiempo (ms)\"\n";
	fin << "plot \"" << nombre1 << ".dat\" using 1:2 with lines title \"" << nombre1 << "\" , \"" << nombre2 << ".dat\" using 1:2 with lines title \"" << nombre2 << "\" , \"" << nombre3 << ".dat\" using 1:2 with lines title \"" << nombre3 << "\" , \"" << nombre4 << ".dat\" using 1:2 with lines title \"" << nombre4 << "\" , \"" << nombre5 << ".dat\" using 1:2 with lines title \"" << nombre5 << "\" , \"" << nombre6 << ".dat\" using 1:2 with lines title \"" << nombre6 << "\" , \"" << nombre7 << ".dat\" using 1:2 with lines title \"" << nombre7 << "\"\n";
	fin << "set terminal pdf\n";
	fin << "set output\"" << nombre1 << nombre2 << nombre3 << nombre4 << nombre5 << nombre6 << nombre7 << ".pdf\" \n";
	fin << "replot\n";
	fin << "pause 5\"Pulsa Enter para continuar...\"";
	fin.close();
}

void  Graficas::generarGraficaCMP3(string nombre1, string nombre2, string nombre3, string nombre4)
{
	ofstream fin("comparaTodosGraficas.plt");
	fin << "set title \"" << nombre1 << " , " << nombre2 << " , " << nombre3 << " , " << nombre4 << "\"\n";
	fin << "set key top left vertical inside\n";
	fin << "set grid\n";
	fin << "set xlabel \"Talla (n)\"\n";
	fin << "set ylabel \"Tiempo (ms)\"\n";
	fin << "plot \"" << nombre1 << ".dat\" using 1:2 with lines title \"" << nombre1 << "\" , \"" << nombre2 << ".dat\" using 1:2 with lines title \"" << nombre2 << "\" , \"" << nombre3 << ".dat\" using 1:2 with lines title \"" << nombre3 << "\" , \"" << nombre4 << ".dat\" using 1:2 with lines title \"" << nombre4 << "\"\n";
	fin << "set terminal pdf\n";
	fin << "set output\"" << nombre1 << nombre2 << nombre3 << nombre4 << ".pdf\" \n";
	fin << "replot\n";
	fin << "pause 5\"Pulsa Enter para continuar...\"";
	fin.close();
}