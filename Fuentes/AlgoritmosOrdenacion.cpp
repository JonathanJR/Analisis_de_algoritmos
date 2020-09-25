#include "AlgoritmosOrdenacion.h"

using namespace std;

AlgoritmosOrdenacion::AlgoritmosOrdenacion() {}
AlgoritmosOrdenacion :: ~AlgoritmosOrdenacion() {}


//BURBUJA

void AlgoritmosOrdenacion::ordenaBurbuja(vector<int> &v){
	int aux_elem;
	int n = v.size();
	for (int i = 0; i < n - 1; i++){
		for (int j = v.size() - 1; j > i; j--){
			if (v[j] < v[j - 1]){
				aux_elem = v[j];
				v[j] = v[j - 1];
				v[j - 1] = aux_elem;
			}
		}
	}
}


//INSERCION

void AlgoritmosOrdenacion::ordenaInsercion(vector<int> &v){
	int x, j, aux;
	int n = v.size();
	for (int i = 1; i < n; i++){
		x = v[i];
		j = i - 1;

		while (j >= 0 && v[j] > x){
			aux = v[j + 1];
			v[j + 1] = v[j];
			v[j] = aux;
			j = j - 1;
		}
	}
}

//SELECCION

void AlgoritmosOrdenacion::ordenaSeleccion(vector<int> &v){
	int posminimo = 0, aux;
	int n = v.size();
	for (int i = 0; i < n; i++){
		posminimo = i;

		for (int j = i + 1; j < n; j++){
			if (v[j] < v[posminimo])
				posminimo = j;
		}
		aux = v[posminimo];
		v[posminimo] = v[i];
		v[i] = aux;
	}
}


//SHELLSORT

void AlgoritmosOrdenacion::ordenaShell(vector<int> &v){
	int n = v.size();
	for (int h = v.size() / 2; h > 0; h /= 2){
		for (int i = h; i < n; i++){
			int j = i;
			int elem = v[i];

			while (j >= h && elem < v[j - h]){
				v[j] = v[j - h];
				j -= h;
			}
			v[j] = elem;
		}
	}
}

//QUICKSORT

void AlgoritmosOrdenacion::ordenaQuickSort(vector<int> &v){
	ordenaQuickSort(v, 0, v.size() - 1);
}

void AlgoritmosOrdenacion::ordenaQuickSort(vector<int> &v, int e, int d){
	if (e < d){
		int q = ordenaQuickSortPartition(v, e, d);
		ordenaQuickSort(v, e, q);
		ordenaQuickSort(v, q + 1, d);
	}
}

int AlgoritmosOrdenacion::ordenaQuickSortPartition(vector<int> &v, int e, int d){
	int x = v[e];
	int i = e - 1;
	int j = d + 1;

	for (;;){
		while (x < v[--j]);
		while (v[++i] < x);

		if (i >= j)
			return j;
		swap(v[i], v[j]);
	}
}


// MERGESORT

void AlgoritmosOrdenacion::ordenaMergeSort(vector<int> &v){
	ordenaMergeSort(v, 0, v.size() - 1);
}

void AlgoritmosOrdenacion::ordenaMergeSort(vector<int> &v, int e, int d){
	if (e < d){
		int m = (e + d) / 2;
		ordenaMergeSort(v, e, m);
		ordenaMergeSort(v, m + 1, d);
		Merge(v, e, m, d);
	}
}

void AlgoritmosOrdenacion::Merge(vector<int> &v, int e, int m, int d){
	vector<int> B(d - e + 1);
	int i = e;
	int j = m + 1;
	int k = 0;

	while (i <= m && j <= d){
		if (v[i] <= v[j])
			B[k++] = v[i++];
		else
			B[k++] = v[j++];
	}

	while (i <= m)
		B[k++] = v[i++];

	while (j <= d)
		B[k++] = v[j++];

	for (k = 0; k <= d - e; ++k)
		v[e + k] = B[k];
}

//HEAPSORT

void heapify(vector<int> &v, int n, int i)
{
	int x = v[i];
	int c = 2 * i + 1;

	while (c < n){
		if (c + 1 < n && v[c] < v[c + 1])
			c++;
		if (x >= v[c])
			break;
		v[i] = v[c];
		i = c;
		c = 2 * i + 1;
	}
	v[i] = x;
}

void build_heap(vector<int> &v){
	int n = v.size();
	for (int i = n / 2; i >= 0; i--)
		heapify(v, n, i);
}

void AlgoritmosOrdenacion::ordenaHeapSort(vector<int> &v){
	int n = v.size();
	build_heap(v);
	for (int i = n - 1; i >= 1; --i){
		swap(v[0], v[i]);
		heapify(v, i, 0);
	}
}


//IMPLEMENTACION CON TAD usando las STL
/*
void AlgoritmosOrdenacion::ordenaHeapSort(vector<int> &v){
	priority_queue <int> pq;
	int n = v.size();
	for (int i = 0; i < n; i++)
		pq.push(v[i]);

	for (int i = v.size() - 1; i >= 0; i--){
		v[i] = pq.top();
		pq.pop();
	}
}
*/