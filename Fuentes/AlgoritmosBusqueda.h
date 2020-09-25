#include <vector>
#include <list>
#include "vectorInt.h"
#include <iostream>

#ifndef _BUSQUEDA
#define _BUSQUEDA

using namespace std;

class AlgoritmosBusqueda{
	vector<list<int> > hash_opened;
public:
	AlgoritmosBusqueda();
	~AlgoritmosBusqueda();

	int busquedaSecuencialIt(vector<int> &v, int key);

	int busquedaBinariaRc(vector<int> &v, int key);

	int BinariaRc(vector<int> &v, int left, int right, int key);

	int BinariaIt(vector<int> &v, int key);

	int busquedaTernariaRc(vector<int> &v, int key);
	int TernariaRc(vector<int> &v, int left, int right, int key);
};
#endif