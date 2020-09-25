# Analisis de algoritmos
Aplicación para el análisis de algoritmos de ordenación (Burbuja, Inserción, Selección, Shell, Quicksort, MergeSort y HeapSort) y búsqueda (Secuencial, Binaria Iterativa, Binaria Recursiva, Ternaria Recursiva).

- El ordenamiento es una labor común que realizamos continuamente, es algo tan corriente en nuestras vidas que no nos detenemos a pensar en ello. Ordenar es simplemente colocar información de una manera especial basándonos en un criterio de ordenamiento.

- En nuestro caso como criterio de ordenamiento aplicaremos varios algoritmos de ordenación que nos servirán para ordenar vectores con valores asignados aleatoriamente. Nos centraremos en los métodos de Burbuja, Inserción y Selección, analizando experimentalmente el comportamiento temporal compararemos dichos algoritmos para poder elegir cual es el más rápido.


Con esta aplicación se pueden analizar los tiempos de los siguientes algoritmos:

Algoritmo Burbuja
- Se basa en el principio de comparar e intercambiar pares de elementos adyacentes hasta que todos estén ordenados.

Algoritmo de Inserción
- Consiste en tomar elemento a elemento e ir insertando cada elemento en su posición correcta de manera que se mantiene el orden de los elementos ya ordenados.

Algoritmo de Selección
- Este método se basa en que cada vez que se mueve un elemento, se lleva a su posición correcta. Se comienza examinando todos los elementos, se localiza el más pequeño y se sitúa en la primera posición. A continuación, se localiza el menor de los restantes y se sitúa en la segunda posición. Se procede de manera similar sucesivamente hasta que quedan dos elementos. Entonces se localiza el menor y se sitúa en la penúltima posición y el último elemento, que será el mayor de todos, ya queda automáticamente colocado en su posición correcta.

Algoritmo Shell
- Este algoritmo es una mejora de la ordenación por inserción. Coloca cada elemento en su posición correcta, moviendo todos los elementos mayores que él una posición a la derecha. Usando los incrementos de Shell (que comienzan con n/2, n el tamaño del vector y se dividen por 2 cada vez).

Algoritmo Quicksort
- Este algoritmo es uno de los más usados y se basa en la estrategia de “divide y vencerás”.

Algoritmo MergeSort
- Este algoritmo también se basa en la estrategia de “divide y vencerás”. Divide los elementos en dos secuencias de la misma longitud aproximadamente para después ordenar de forma independiente cada subsecuencia. Finalmente mezcla las dos secuencias ordenadas para producir la secuencia final ordenada.

Algoritmo HeapSort
- Se basa en el uso de una estructura de datos llamada montículo, que son implementaciones eficientes de las colas de prioridad. 

Algoritmo Búsqueda Secuencial
- Busca un dato (clave) key en una lista o array V accediendo a todas las posiciones hasta que se encuentre el elemento o se llegue al final del mismo (elemento no está).

Algoritmo Búsqueda Binaria Iterativa
- Para este algoritmo, se sitúa la lectura en el centro de la lista y se comprueba si la clave coincide con el valor del elemento central. Si no se encuentra el valor de la clave, se sitúa en la mitad inferior o superior del elemento central de la lista. El algoritmo termina o bien porque se ha encontrado la clave o porque el valor del índice izquierdo excede al derecho y el algoritmo devuelve el indicador de fallo, -1 (búsqueda no encontrada).

Algoritmo Búsqueda Binaria Recursiva
- La estrategia a seguir es la misma que en el caso iterativo.

Algoritmo Búsqueda Ternaria Recursiva
- El modo de proceder de este algoritmo es el siguiente: primero compara con el elemento en posición n/3 del vector, si éste es menor que el elemento x a buscar entonces compara con el elemento en posición 2n/3, y si no coincide con x busca recursivamente en el correspondiente subvector de tamaño 1/3 del original.
