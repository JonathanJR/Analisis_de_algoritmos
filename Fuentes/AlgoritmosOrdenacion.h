#include <algorithm>
#include <queue>
#include <vector>

#ifndef _ORDENACION
#define _ORDENACION

using namespace std;

class AlgoritmosOrdenacion{
public:
	AlgoritmosOrdenacion();
	~AlgoritmosOrdenacion();

	void ordenaBurbuja(vector<int> &v);

	void ordenaInsercion(vector<int> &v);

	void ordenaSeleccion(vector<int> &v);

	void ordenaShell(vector<int> &v);

	void ordenaQuickSort(vector<int> &v);
	void ordenaQuickSort(vector<int> &v, int izq, int der);
	int ordenaQuickSortPartition(vector<int> &v, int izq, int der);

	void ordenaMergeSort(vector<int> &v);
	void ordenaMergeSort(vector<int> &v, int e, int d);
	void Merge(vector<int> &v, int e, int m, int d);

	void ordenaHeapSort(vector<int> &v);
};
#endif