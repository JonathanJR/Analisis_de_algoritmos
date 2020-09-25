#include "AlgoritmosBusqueda.h"
#include <cmath>

using namespace std;

AlgoritmosBusqueda::AlgoritmosBusqueda() { }
AlgoritmosBusqueda:: ~AlgoritmosBusqueda() { }

//SECUENCIAL ITERATIVA

int AlgoritmosBusqueda::busquedaSecuencialIt(vector<int> &v, int key)
{
	int i = 0;
	int n = v.size();
	while (v[i] != key && i <= n) {
		i = i + 1;
	}
	if (v[i] == key) {
		return i;
	}
	else
		return -1;
}

//BINARIA RECURSIVA

int AlgoritmosBusqueda::busquedaBinariaRc(vector<int> &v, int key)
{
	return BinariaRc(v, 0, v.size() - 1, key);
}

int AlgoritmosBusqueda::BinariaRc(vector<int> &v, int primero, int ultimo, int clave)
{
	if (primero > ultimo) {
		return -1;
	}

	int mitad = (ultimo + primero) / 2;

	if (v[mitad] == clave){
		return mitad;
	}
	else{
		if (clave < v[mitad])
			return BinariaRc(v, primero, mitad - 1, clave);
		else
			if (clave > v[mitad])
				return BinariaRc(v, mitad + 1, ultimo, clave);
	}
	return -1;
}

//BINARIA ITERATIVA

int AlgoritmosBusqueda::BinariaIt(vector<int> &v, int key)
{
	int mitad, primero = 0, ultimo = v.size();
	while (primero <= ultimo){
		mitad = (primero + ultimo) / 2;
		if (key == v[mitad]){
			return mitad;
		}
		else{
			if (key < v[mitad]){
				ultimo = mitad - 1;
			}
			else{
				primero = mitad + 1;
			}
		}
	}
	return -1;
}

//EXAMEN DE MODIFICACION - TERNARIA

int AlgoritmosBusqueda::busquedaTernariaRc(vector<int> &v, int key)
{
	return TernariaRc(v, 0, v.size() - 1, key);
}

int AlgoritmosBusqueda::TernariaRc(vector<int> &v, int primero, int ultimo, int clave)
{
	int tercio = 0, dostercios = 0;
	if (primero == ultimo){
		if (clave == v[primero])
			return primero;
		else
			return -1;
	}
	if (ultimo - primero == 1){
		if (clave == v[primero])
			return primero;

		if (clave == v[ultimo])
			return ultimo;

		return -1;
	}

	tercio = ((ultimo - primero + 1) / 3) + primero;
	dostercios = (ultimo - tercio) + primero;

	if (clave == v[tercio])
		return tercio;
	else
		if (clave < v[tercio])
			return TernariaRc(v, primero, tercio - 1, clave);
		else
			if (clave == v[dostercios])
				return dostercios;
			else
				if (clave < v[dostercios])
					return TernariaRc(v, tercio + 1, dostercios - 1, clave);
				else
					return TernariaRc(v, dostercios + 1, ultimo, clave);
}

//HASHSEARCH
