#include "TestOrdenacion.h"
#include "TestBusqueda.h"
#include <iostream>
using namespace std;

void cabecera(){
	cout << "\t\t\t\t\t***AMC.Practica 1.Curso 17/18***\n";
	cout << "\t\t\t\t\tAlumno. Jonathan Jimenez Reina\n\n\n\n";
	cout << "\t\t\t\t***MENU PRINCIPAL***\t\t\t\n";
}

int menu() {
	system("color 3F");
	int opcion;
	cabecera();
	cout << "\t***ANALISIS EXPERIMENTAL DE ALGORITMOS DE ORDENACION Y BUSQUEDA***\n\n";
	cout << "\t\t1.- MENU ORDENACION\n";
	cout << "\t\t2.- MENU BUSQUEDA\n";
	cout << "\t\t0.- Salir\n";
	cout << "\t\t____________\n\n";
	cout << "\t\tElige opcion :\t";
	do {
		cin >> opcion;
	} while ((opcion > 2) || (opcion < 0));
	return opcion;
}

int menuBusqueda() {
	system("color 3F");
	int opcion;
	cabecera();
	cout << "\t***ANALISIS EXPERIMENTAL DE ALGORITMOS DE BUSQUEDA***\n\n";
	cout << "\t\t1.- Probar metodos busqueda\n";
	cout << "\t\t2.- Obtener el caso medio de un metodo de busqueda\n";
	cout << "\t\t3.- Comparar dos metodos\n";
	cout << "\t\t4.- Comparar TODOS\n";
	cout << "\t\t0.- Volver al menu principal\n";
	cout << "\t\t____________\n\n";
	cout << "\t\tElige opcion :\t";
	do {
		cin >> opcion;
	} while ((opcion > 4) || (opcion < 0));
	return opcion;
}

int menuOrdenacion() {
	system("color 3F");
	int opcion;
	cabecera();
	cout << "\t***ANALISIS EXPERIMENTAL DE ALGORITMOS DE ORDENACION***\n\n";
	cout << "\t\t1.- Probar metodos ordenacion\n";
	cout << "\t\t2.- Obtener el caso medio de un metodo de ordenacion\n";
	cout << "\t\t3.- Comparar dos metodos\n";
	cout << "\t\t4.- Comparar TODOS\n";
	cout << "\t\t0.- Volver al menu principal\n";
	cout << "\t\t____________\n\n";
	cout << "\t\tElige opcion :\t";
	do {
		cin >> opcion;
	} while ((opcion > 4) || (opcion < 0));
	return opcion;
}

int submenuBusquedaMedio() {
	int opcionSub;
	cout << "\n\n\t\t***Metodo a estudiar para el caso medio***\n\n";
	cout << "\t\t0.- Busqueda Secuencial Iterativa\n\n";
	cout << "\t\t1.- Busqueda Binaria Recursiva\n\n";
	cout << "\t\t2.- Busqueda Binaria Iterativa\n\n";
	cout << "\t\t3.- Busqueda Ternaria Recursiva\n\n";
	cout << "\t\t4.- Busqueda Hash\n\n";
	cout << "\t\t____________\n\n";
	cout << "\t\tElige opcion :\t";
	do {
		cin >> opcionSub;
	} while ((opcionSub > 5) || (opcionSub < 0));
	return opcionSub;
}

int submenuOrdenacionMedio() {
	int opcionSub;
	cout << "\n\n\t\t***Metodo a estudiar para el caso medio***\n\n";
	cout << "\t\t0.- Burbuja\n\n";
	cout << "\t\t1.- Insercion\n\n";
	cout << "\t\t2.- Seleccion\n\n";
	cout << "\t\t3.- Shell\n\n";
	cout << "\t\t4.- Quick-Sort\n\n";
	cout << "\t\t5.- Mergesort\n\n";
	cout << "\t\t6.- Heapsort\n\n";
	cout << "\t\t____________\n\n";
	cout << "\t\tElige opcion :\t";
	do {
		cin >> opcionSub;
	} while ((opcionSub > 6) || (opcionSub < 0));
	return opcionSub;
}

int submenuCompBusqueda1() {
	int opcion;
	cout << "\n\n\t\t***COMPARACION DE DOS METODOS DE BUSQUEDA***\n";
	cout << "\n\t\tSelecciona los dos metodos a comparar\n\n";
	cout << "\t\t0.- Busqueda Secuencial Iterativa\n\n";
	cout << "\t\t1.- Busqueda Binaria Recursiva\n\n";
	cout << "\t\t2.- Busqueda Binaria Iterativa\n\n";
	cout << "\t\t3.- Busqueda Ternaria Recursiva\n\n";
	cout << "\t\t4.- Busqueda Hash\n\n";
	cout << "\t\tElige metodo 1: ";
	do {
		cin >> opcion;
	} while ((opcion > 5) || (opcion < 0));
	return opcion;
}

int submenuCompOrdenacion1() {
	int opcion;
	cout << "\n\n\t\t***COMPARACION DE DOS METODOS DE ORDENACION***\n";
	cout << "\n\t\tSelecciona los dos metodos a comparar\n\n";
	cout << "\t\t0.- Burbuja\n\n";
	cout << "\t\t1.- Insercion\n\n";
	cout << "\t\t2.- Seleccion\n\n";
	cout << "\t\t3.- Shell\n\n";
	cout << "\t\t4.- Quick-Sort\n\n";
	cout << "\t\t5.- Mergesort\n\n";
	cout << "\t\t6.- Heapsort\n\n";
	cout << "\t\tElige metodo 1: ";
	do {
		cin >> opcion;
	} while ((opcion > 6) || (opcion < 0));
	return opcion;
}

int submenuCompBusqueda2() {
	int opcion;
	cout << "\n\t\tElige metodo 2: ";
	do {
		cin >> opcion;
	} while ((opcion > 5) || (opcion < 0));
	return opcion;
}

int submenuCompOrdenacion2() {
	int opcion;
	cout << "\n\t\tElige metodo 2: ";
	do {
		cin >> opcion;
	} while ((opcion > 8) || (opcion < 0));
	return opcion;
}

int main() {
	TestOrdenacion c;
	TestBusqueda b;
	int opcion, opcionSub, opcion1, opcion2;
	do {
		system("cls");
		opcion = menu();
		if (opcion == 1){
			system("cls");
			opcion = menuOrdenacion();
			switch (opcion) {
			case 1:
				system("cls");
				c.comprobarMetodosOrdenacion();
				break;
			case 2:
				system("cls");
				opcionSub = submenuOrdenacionMedio();
				c.casoMedio(opcionSub);
				break;
			case 3:
				system("cls");
				opcion1 = submenuCompOrdenacion1();
				opcion2 = submenuCompOrdenacion2();
				c.comparar(opcion1, opcion2);
				system("cls");
				break;
			case 4:
				system("cls");
				c.compararTodos();
				break;
			case 0:
				system("cls");
				main();
				break;
			default: {}
			}
		}
		else{
			if (opcion == 2){
				system("cls");
				opcion = menuBusqueda();
				switch (opcion) {
				case 1:
					system("cls");
					b.comprobarMetodosBusqueda();
					break;
				case 2:
					system("cls");
					opcionSub = submenuBusquedaMedio();
					b.casoMedio(opcionSub);
					break;
				case 3:
					system("cls");
					opcion1 = submenuCompBusqueda1();
					opcion2 = submenuCompBusqueda2();
					b.comparar(opcion1, opcion2);
					system("cls");
					break;
				case 4:
					system("cls");
					b.compararTodos();
					break;
				case 0:
					system("cls");
					main();
					break;
				default: {}
				}
			}
		}
	} while (opcion != 0);
	return 0;
}