/* Constantes simbolicas para indicar el metodo de ordenacion*/
enum algoritmosOrdenacion { BURBUJA, INSERCION, SELECCION, SHELL, QUICKSORT, MERGESORT, HEAPSORT };
/* Constantes simbolicas para indicar el metodo de busqueda*/
enum algoritmosBusqueda { SECUENCIALIt, BINARIARc, BINARIAIt, TERNARIARc, HASH };
/* Constantes para indicar el Orden del metodo de ordenacion*/
enum ordenes { CUADRADO, NlogN, OSHELL, logN, N };
/* Constantes para indicar el Numero de repeticiones para el caso medio de cada mйtodo de bъsqueda */
static const int NUMREPETICIONES = 10;
/* Constantes para indicar la variacion de las tallas del vector */
enum valoresTallas { tallaIni = 50, tallaFin = 500, incTalla = 50 };