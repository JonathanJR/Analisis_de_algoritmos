set title "SecuencialI y BinariaR"
set key top left vertical inside
set grid
set xlabel "Talla (n)"
set ylabel "Tiempo (ms)"
plot "SecuencialI.dat" using 1:2 with lines title "SecuencialI" , "BinariaR.dat" using 1:2 with lines title "BinariaR"
set terminal pdf
set output"SecuencialIBinariaR.pdf" 
replot
pause 5"Pulsa Enter para continuar..."