#include "TestBusqueda.h"
#include "Constantes.h"
#include "AlgoritmosBusqueda.h"
#include "AlgoritmosOrdenacion.h"
#include "Graficas.h"
#include "Mtime.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iostream>
using namespace std;

TestBusqueda::TestBusqueda()
{
	nombreAlgoritmo.push_back("SecuencialI");
	nombreAlgoritmo.push_back("BinariaR");
	nombreAlgoritmo.push_back("BinariaIt");
	nombreAlgoritmo.push_back("TernariaR");
	nombreAlgoritmo.push_back("Hash");
}
TestBusqueda::~TestBusqueda(){}


double TestBusqueda::buscaEnArrayDeInt(vector<int> &v, int metodo, int key, int &posicion)
{
	AlgoritmosBusqueda estrategia;
	Mtime t;
	LARGE_INTEGER t_inicial, t_final;
	QueryPerformanceCounter(&t_inicial);
	// Invoca al metodo de busqueda elegido
	switch (metodo)
	{
	case SECUENCIALIt: posicion = estrategia.busquedaSecuencialIt(v, key);
		break;
	case BINARIARc: posicion = estrategia.busquedaBinariaRc(v, key);
		break;
	case BINARIAIt: posicion = estrategia.BinariaIt(v, key);
		break;
	case TERNARIARc: posicion = estrategia.busquedaTernariaRc(v, key);
		break;
	//case HASH: estrategia.
	//	break;
	}
	QueryPerformanceCounter(&t_final);
	return t.performancecounter_diff(&t_final, &t_inicial) * 1000000;
}


void TestBusqueda::comprobarMetodosBusqueda() {
	int numalgoritmos = nombreAlgoritmo.size();
	int talla;
	vectorInt vInt;

	cout << endl << endl << "Introduce la talla: ";
	cin >> talla;

	vector<int> v(talla);
	vInt.GeneraVector(v);

	system("cls");
	AlgoritmosOrdenacion AlOrdena;
	AlgoritmosBusqueda estrategia;

	for (int metodo = 0; metodo < numalgoritmos; metodo++) {
		AlOrdena.ordenaQuickSort(v);

		cout << endl << endl << "vector para el metodo " << nombreAlgoritmo[metodo] << ":" << endl << endl;
		vInt.MuestraVector(v);
		int key;
		cout << endl << endl << "Introduce la clave a buscar: ";
		cin >> key;
		int posicion;
		buscaEnArrayDeInt(v, metodo, key, posicion);
		cout << endl << endl << "posicion de " << key << " buscado con el metodo " << nombreAlgoritmo[metodo] << " : " << posicion << endl << endl;
		system("pause");
		system("cls");
	}
	system("cls");
}


void TestBusqueda::casoMedio(int metodo)
{
	char opcion;
	Graficas p;
	double time = 0;
	int posicion;
	AlgoritmosOrdenacion AlOrdena;
	vectorInt vInt;
	ofstream fout(nombreAlgoritmo[metodo] + ".dat");
	cout << "\n\t*** Ordenacion por " << nombreAlgoritmo[metodo] << " ***\n";
	cout << "\n\tTiempos de ejecucion promedio\n\n\n";
	cout << "\tTalla\t\tTiempo(mseg)\n\n";
	for (int talla = tallaIni; talla <= tallaFin; talla = talla + incTalla) {
		vector<int> v(talla);

		int contador = 0;

		while (contador < NUMREPETICIONES){
			vInt.GeneraVector(v);
			AlOrdena.ordenaQuickSort(v);
			time += buscaEnArrayDeInt(v, metodo, v[talla / 2], posicion);
			contador++;
		}

		time = time / NUMREPETICIONES;
		cout << "\t" << talla << "\t\t" << time << endl;
		fout << talla << "\t" << time << "\t\n";
	}

	fout.close();
	cout << "\n\nDatos guardados en el fichero " << nombreAlgoritmo[metodo] << ".dat\n\n";
	cout << "Generar grafica de resultados? (s/n):\t";
	do {
		cin >> opcion;
	} while ((opcion != 's') && (opcion != 'n'));
	if (opcion == 's') {
		cout << "\nGrafica guardada en el fichero " << nombreAlgoritmo[metodo] << ".pdf\n";

		if (metodo == SECUENCIALIt)
			p.generarGraficaMEDIO(nombreAlgoritmo[metodo], N);
		else
			p.generarGraficaMEDIO(nombreAlgoritmo[metodo], logN);

		system("medioGrafica.plt");
		system("pause");
	}
}


void TestBusqueda::comparar(int metodo1, int metodo2)
{
	char opcion;
	Graficas p;
	double time1 = 0, time2 = 0;
	int posicion;
	AlgoritmosOrdenacion AlOrdena;

	ofstream fout1(nombreAlgoritmo[metodo1] + ".dat");
	ofstream fout2(nombreAlgoritmo[metodo2] + ".dat");
	vectorInt vInt;

	cout << "\n\t\t*** Ordenacion por " << nombreAlgoritmo[metodo1] << " y " << nombreAlgoritmo[metodo2] << " ***\n";
	cout << "\n\t\t\tTiempos de ejecucion promedio\n\n";
	cout << "\t\t\t " << nombreAlgoritmo[metodo1] << "\t " << nombreAlgoritmo[metodo2] << endl << endl;
	cout << "\tTalla(n)\tTiempo(mseg)\tTiempo(mseg)\n\n";


	for (int talla = tallaIni; talla <= tallaFin; talla = talla + incTalla) {
		vector<int> v(talla);

		int contador = 0;

		while (contador < NUMREPETICIONES)
		{
			vInt.GeneraVector(v);
			AlOrdena.ordenaQuickSort(v);
			time1 += buscaEnArrayDeInt(v, metodo1, v[talla / 2], posicion);
			time2 += buscaEnArrayDeInt(v, metodo2, v[talla / 2], posicion);
			contador++;
		}

		time1 = time1 / NUMREPETICIONES;
		time2 = time2 / NUMREPETICIONES;

		cout << "\t" << talla << "\t\t " << time1 << "\t " << time2 << endl;
		fout1 << talla << "\t" << time1 << "\t\n";
		fout2 << talla << "\t" << time2 << "\t\n";
	}

	fout1.close();
	fout2.close();
	cout << "\n\nDatos guardados en el fichero " << nombreAlgoritmo[metodo1] << ".dat y " << nombreAlgoritmo[metodo2] << ".dat\n\n";
	cout << "Generar grafica de resultados?(s/n):\t";
	do {
		cin >> opcion;
	} while ((opcion != 's') && (opcion != 'n'));
	if (opcion == 's') {
		cout << "\nGrafica guardada en el fichero " << nombreAlgoritmo[metodo1] << nombreAlgoritmo[metodo2] << ".pdf\n";
		p.generarGraficaCMP(nombreAlgoritmo[metodo1], nombreAlgoritmo[metodo2]);
		system("comparaDosGraficas.plt");
		system("pause");
	}
}

// NO PEDIDO EN PRACTICA //

void TestBusqueda::compararTodos() {
	char opcion;
	Graficas p;
	double time0 = 0, time1 = 0, time2 = 0, time3 = 0;
	int posicion;
	AlgoritmosOrdenacion AlOrdena;
	vectorInt vInt;

	ofstream fout1(nombreAlgoritmo[0] + ".dat");
	ofstream fout2(nombreAlgoritmo[1] + ".dat");
	ofstream fout3(nombreAlgoritmo[2] + ".dat");
	ofstream fout4(nombreAlgoritmo[3] + ".dat");

	cout << "\n\t\t*** Ordenacion por " << nombreAlgoritmo[0] << " , " << nombreAlgoritmo[1] << " , " << nombreAlgoritmo[2] << " , " << nombreAlgoritmo[3] << " ***\n";
	cout << "\n\t\t\tTiempos de ejecucion promedio\n\n";
	cout << "\t\t\t " << nombreAlgoritmo[0] << "\t " << nombreAlgoritmo[1] << "\t " << nombreAlgoritmo[2] << "\t " << nombreAlgoritmo[3] << endl << endl;
	cout << "\tTalla(n)\tTiempo(mseg)\tTiempo(mseg)\tTiempo(mseg)\tTiempo\n\n";

	for (int talla = tallaIni; talla <= tallaFin; talla = talla + incTalla) {
		vector<int> v(talla);

		int contador = 0;

		while (contador < NUMREPETICIONES)
		{
			vInt.GeneraVector(v);
			AlOrdena.ordenaQuickSort(v);
			time0 += buscaEnArrayDeInt(v, 0, v[talla / 2], posicion);
			time1 += buscaEnArrayDeInt(v, 1, v[talla / 2], posicion);
			time2 += buscaEnArrayDeInt(v, 2, v[talla / 2], posicion);
			time3 += buscaEnArrayDeInt(v, 3, v[talla / 2], posicion);
			contador++;
		}

		time0 = time0 / NUMREPETICIONES;
		time1 = time1 / NUMREPETICIONES;
		time2 = time2 / NUMREPETICIONES;
		time3 = time3 / NUMREPETICIONES;

		cout << "\t" << talla << "\t\t " << time0 << "\t " << time1 << "\t " << time2 << "\t " << time3 << endl;
		fout1 << talla << "\t" << time0 << "\t\n";
		fout2 << talla << "\t" << time1 << "\t\n";
		fout3 << talla << "\t" << time2 << "\t\n";
		fout4 << talla << "\t" << time3 << "\t\n";
	}
	fout1.close();
	fout2.close();
	fout3.close();
	fout4.close();
	cout << "\n\nDatos guardados en el fichero " << nombreAlgoritmo[0] << ".dat , " << nombreAlgoritmo[1] << ".dat , " << nombreAlgoritmo[2] << ".dat , " << nombreAlgoritmo[3] << ".dat\n\n";
	cout << "Generar grafica de resultados?(s/n):\t";
	do {
		cin >> opcion;
	} while ((opcion != 's') && (opcion != 'n'));
	if (opcion == 's') {
		cout << "\nGrafica guardada en el fichero " << nombreAlgoritmo[0] << nombreAlgoritmo[1] << nombreAlgoritmo[2] << nombreAlgoritmo[3] << ".pdf\n";
		p.generarGraficaCMP3(nombreAlgoritmo[0], nombreAlgoritmo[1], nombreAlgoritmo[2], nombreAlgoritmo[3]);
		system("comparaTodosGraficas.plt");
		system("pause");
	}
}