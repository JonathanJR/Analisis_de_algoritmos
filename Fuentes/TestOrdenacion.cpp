#include "TestOrdenacion.h"
#include "Graficas.h"
#include "Mtime.h"
#include "Constantes.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;


TestOrdenacion::TestOrdenacion()
{
	nombreAlgoritmo.push_back("Burbuja");
	nombreAlgoritmo.push_back("Insercion");
	nombreAlgoritmo.push_back("Seleccion");
	nombreAlgoritmo.push_back("Shell");
	nombreAlgoritmo.push_back("QuickSort");
	nombreAlgoritmo.push_back("Mergesort");
	nombreAlgoritmo.push_back("Heapsort");
}
TestOrdenacion::~TestOrdenacion() {}


double TestOrdenacion::ordenarArrayDeInt(vector<int> &v, int metodo)
{
	AlgoritmosOrdenacion estrategia;
	Mtime t;
	LARGE_INTEGER t_inicial, t_final;
	QueryPerformanceCounter(&t_inicial);
	// Invoca al metodo de ordenacion elegido
	switch (metodo) {
	case BURBUJA: estrategia.ordenaBurbuja(v);
		break;
	case INSERCION: estrategia.ordenaInsercion(v);
		break;
	case SELECCION: estrategia.ordenaSeleccion(v);
		break;
	case SHELL: estrategia.ordenaShell(v);
		break;
	case QUICKSORT: estrategia.ordenaQuickSort(v);
		break;
	case MERGESORT: estrategia.ordenaMergeSort(v);
		break;
	case HEAPSORT: estrategia.ordenaHeapSort(v);
		break;
	}
	QueryPerformanceCounter(&t_final);
	return t.performancecounter_diff(&t_final, &t_inicial) * 1000;
}


void TestOrdenacion::comprobarMetodosOrdenacion(){
	int numalgoritmos = nombreAlgoritmo.size();
	int talla;
	vectorInt vInt;

	cout << endl << endl << "Introduce la talla: ";
	cin >> talla;

	vector<int> v(talla);
	vInt.GeneraVector(v);

	vector<int> copia = v;

	system("cls");

	for (int metodo = 0; metodo < numalgoritmos; metodo++) {

		cout << endl << endl << "Vector inicial para el metodo " << nombreAlgoritmo[metodo] << ":" << endl << endl;
		vInt.MuestraVector(v);

		ordenarArrayDeInt(v, metodo);
		cout << endl << endl << "Array ordenado con metodo " << nombreAlgoritmo[metodo] << ":" << endl << endl;

		vInt.MuestraVector(v);

		cout << endl;
		v = copia;
		system("pause");
		system("cls");
	}
	system("cls");
}


void TestOrdenacion::casoMedio(int metodo)
{
	char opcion;
	Graficas p;
	double time = 0, tiempo;

	vectorInt vInt;
	string algoritmo = nombreAlgoritmo[metodo];

	ofstream fout(algoritmo + ".dat");
	cout << "\n\t*** Ordenacion por " << algoritmo << " ***\n";
	cout << "\n\tTiempos de ejecucion promedio\n\n\n";
	cout << "\tTalla\t\tTiempo(mseg)\n\n";

	for (int talla = tallaIni; talla <= tallaFin; talla = talla + incTalla) {
		vector<int> v(talla);

		int contador = 0;
		time = 0;

		while (contador < NUMREPETICIONES)
		{
			vInt.GeneraVector(v);
			time += ordenarArrayDeInt(v, metodo);
			contador++;
		}
		tiempo = time / NUMREPETICIONES;
		cout << "\t" << talla << "\t\t" << time << endl;
		fout << talla << "\t" << time << "\t\n";
	}

	fout.close();
	cout << "\n\nDatos guardados en el fichero " << algoritmo << ".dat\n\n";
	cout << "Generar grafica de resultados? (s/n):\t";
	do {
		cin >> opcion;
	} while ((opcion != 's') && (opcion != 'n'));
	if (opcion == 's') {
		cout << "\nGrafica guardada en el fichero " << algoritmo << ".pdf\n";
		if (metodo == BURBUJA || metodo == INSERCION || metodo == SELECCION)
			p.generarGraficaMEDIO(algoritmo, CUADRADO);
		else if (metodo == SHELL)
			p.generarGraficaMEDIO(algoritmo, OSHELL);
		else
			p.generarGraficaMEDIO(algoritmo, NlogN);

		system("medioGrafica.plt");
		system("pause");
	}
}


void TestOrdenacion::comparar(int metodo1, int metodo2) {
	char opcion;
	Graficas p;
	double time1 = 0, time2 = 0, tiempo1, tiempo2;

	string algoritmo1 = nombreAlgoritmo[metodo1];
	string algoritmo2 = nombreAlgoritmo[metodo2];

	ofstream fout1(algoritmo1 + ".dat");
	ofstream fout2(algoritmo2 + ".dat");

	cout << "\n\t\t*** Ordenacion por " << algoritmo1 << " y " << algoritmo2 << " ***\n";
	cout << "\n\t\t\tTiempos de ejecucion promedio\n\n";
	cout << "\t\t\t " << algoritmo1 << "\t " << algoritmo2 << endl << endl;
	cout << "\tTalla(n)\tTiempo(mseg)\tTiempo(mseg)\n\n";

	for (int talla = tallaIni; talla <= tallaFin; talla = talla + incTalla) {
		vector<int> v1(talla);
		vector<int> v2(talla);
		vectorInt vInt;

		int contador = 0;
		while (contador < NUMREPETICIONES)
		{
			vInt.GeneraVector(v1);
			vInt.GeneraVector(v2);
			time1 += ordenarArrayDeInt(v1, metodo1);
			time2 += ordenarArrayDeInt(v2, metodo2);
			contador++;
		}
		tiempo1 = time1 / NUMREPETICIONES;
		tiempo2 = time2 / NUMREPETICIONES;

		cout << "\t" << talla << "\t\t " << tiempo1 << "\t " << tiempo2 << endl;
		fout1 << talla << "\t" << tiempo1 << "\t\n";
		fout2 << talla << "\t" << tiempo2 << "\t\n";
	}

	fout1.close();
	fout2.close();
	cout << "\n\nDatos guardados en el fichero " << algoritmo1 << ".dat y " << algoritmo2 << ".dat\n\n";
	cout << "Generar grafica de resultados?(s/n):\t";
	do {
		cin >> opcion;
	} while ((opcion != 's') && (opcion != 'n'));
	if (opcion == 's') {
		cout << "\nGrafica guardada en el fichero " << algoritmo1 << algoritmo2 << ".pdf\n";
		p.generarGraficaCMP(algoritmo1, algoritmo2);
		system("comparaDosGraficas.plt");
		system("pause");
	}
}

void TestOrdenacion::compararTodos() {
	char opcion;
	Graficas p;
	double time0 = 0, time1 = 0, time2 = 0, time3 = 0, time4 = 0, time5 = 0, time6 = 0;

	ofstream fout1(nombreAlgoritmo[0] + ".dat");
	ofstream fout2(nombreAlgoritmo[1] + ".dat");
	ofstream fout3(nombreAlgoritmo[2] + ".dat");
	ofstream fout4(nombreAlgoritmo[3] + ".dat");
	ofstream fout5(nombreAlgoritmo[4] + ".dat");
	ofstream fout6(nombreAlgoritmo[5] + ".dat");
	ofstream fout7(nombreAlgoritmo[6] + ".dat");

	cout << "\n\t\t*** Ordenacion por " << nombreAlgoritmo[0] << " , " << nombreAlgoritmo[1] << " , " << nombreAlgoritmo[2] << " , " << nombreAlgoritmo[3] << " , " << nombreAlgoritmo[4] << " , " << nombreAlgoritmo[5] << " y " << nombreAlgoritmo[6] << " ***\n";
	cout << "\n\t\t\tTiempos de ejecucion promedio\n\n";
	cout << "\t\t\t " << nombreAlgoritmo[0] << "\t " << nombreAlgoritmo[1] << "\t " << nombreAlgoritmo[2] << "\t " << nombreAlgoritmo[3] << "\t " << nombreAlgoritmo[4] << "\t " << nombreAlgoritmo[5] << "\t " << nombreAlgoritmo[6] << "\t " << endl << endl;
	cout << "\tTalla(n)\tTiempo(mseg)\tTiempo(mseg)\tTiempo(mseg)\tTiempo(mseg)\tTiempo(mseg)\n\n";

	for (int talla = tallaIni; talla <= tallaFin; talla = talla + incTalla) {

		vector<int> v0(talla);
		vector<int> v1(talla);
		vector<int> v2(talla);
		vector<int> v3(talla);
		vector<int> v4(talla);
		vector<int> v5(talla);
		vector<int> v6(talla);
		vectorInt vInt;

		int contador = 0;

		while (contador < NUMREPETICIONES)
		{
			vInt.GeneraVector(v0);
			vInt.GeneraVector(v1);
			vInt.GeneraVector(v2);
			vInt.GeneraVector(v3);
			vInt.GeneraVector(v4);
			vInt.GeneraVector(v5);
			vInt.GeneraVector(v6);

			time0 += ordenarArrayDeInt(v0, 0);
			time1 += ordenarArrayDeInt(v1, 1);
			time2 += ordenarArrayDeInt(v2, 2);
			time3 += ordenarArrayDeInt(v3, 3);
			time4 += ordenarArrayDeInt(v4, 4);
			time5 += ordenarArrayDeInt(v5, 5);
			time6 += ordenarArrayDeInt(v6, 6);
			contador++;
		}

		time0 = time0 / NUMREPETICIONES;
		time1 = time1 / NUMREPETICIONES;
		time2 = time2 / NUMREPETICIONES;
		time3 = time3 / NUMREPETICIONES;
		time4 = time4 / NUMREPETICIONES;
		time5 = time5 / NUMREPETICIONES;
		time6 = time6 / NUMREPETICIONES;

		cout << "\t" << talla << "\t\t " << time0 << "\t " << time1 << "\t " << time2 << "\t " << time3 << "\t " << time4 << "\t " << time5 << "\t " << time6 << endl;
		fout1 << talla << "\t" << time0 << "\t\n";
		fout2 << talla << "\t" << time1 << "\t\n";
		fout3 << talla << "\t" << time2 << "\t\n";
		fout4 << talla << "\t" << time3 << "\t\n";
		fout5 << talla << "\t" << time4 << "\t\n";
		fout6 << talla << "\t" << time5 << "\t\n";
		fout7 << talla << "\t" << time6 << "\t\n";
	}
	fout1.close();
	fout2.close();
	fout3.close();
	fout4.close();
	fout5.close();
	fout6.close();
	fout7.close();
	cout << "\n\nDatos guardados en el fichero " << nombreAlgoritmo[0] << ".dat , " << nombreAlgoritmo[1] << ".dat , " << nombreAlgoritmo[2] << ".dat , " << nombreAlgoritmo[3] << ".dat , " << nombreAlgoritmo[4] << ".dat , " << nombreAlgoritmo[5] << ".dat y " << nombreAlgoritmo[6] << ".dat\n\n";
	cout << "Generar grafica de resultados?(s/n):\t";
	do {
		cin >> opcion;
	} while ((opcion != 's') && (opcion != 'n'));
	if (opcion == 's') {
		cout << "\nGrafica guardada en el fichero " << nombreAlgoritmo[0] << nombreAlgoritmo[1] << nombreAlgoritmo[2] << nombreAlgoritmo[3] << nombreAlgoritmo[4] << nombreAlgoritmo[5] << nombreAlgoritmo[6] << ".pdf\n";
		p.generarGraficaCMP2(nombreAlgoritmo[0], nombreAlgoritmo[1], nombreAlgoritmo[2], nombreAlgoritmo[3], nombreAlgoritmo[4], nombreAlgoritmo[5], nombreAlgoritmo[6]);
		system("comparaTodosGraficas.plt");
		system("pause");
	}
}