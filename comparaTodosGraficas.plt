set title "Burbuja , Insercion , Seleccion , Shell , QuickSort , Mergesort y Heapsort"
set key top left vertical inside
set grid
set xlabel "Talla (n)"
set ylabel "Tiempo (ms)"
plot "Burbuja.dat" using 1:2 with lines title "Burbuja" , "Insercion.dat" using 1:2 with lines title "Insercion" , "Seleccion.dat" using 1:2 with lines title "Seleccion" , "Shell.dat" using 1:2 with lines title "Shell" , "QuickSort.dat" using 1:2 with lines title "QuickSort" , "Mergesort.dat" using 1:2 with lines title "Mergesort" , "Heapsort.dat" using 1:2 with lines title "Heapsort"
set terminal pdf
set output"BurbujaInsercionSeleccionShellQuickSortMergesortHeapsort.pdf" 
replot
pause 5"Pulsa Enter para continuar..."