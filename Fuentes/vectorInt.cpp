#include "vectorInt.h"
#include <random>
#include <iostream>
using namespace std;

vectorInt::vectorInt(){}

void vectorInt::GeneraVector(vector<int> &v){
	random_device rd;     //Inicializamos la semilla
	mt19937 rng(rd());    //Generamos un numero aleatorio
	uniform_int_distribution<int> uni(0, 5000);

	int n = v.size();

	for (int i = 0; i < n; i++){
		v[i] = uni(rng);
	}
}

void vectorInt::MuestraVector(vector<int> &v){
	int n = v.size();
	for (int i = 0; i < n; i++){
		cout << v[i] << "\t";
	}
}

