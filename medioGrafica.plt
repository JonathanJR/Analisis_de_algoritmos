set title "TernariaR"
set key top left vertical inside
set grid
set xlabel "Talla (n)"
set ylabel "Tiempo (ms)"
Logaritmico(x) = a*log(x) + b
fit Logaritmico(x) "TernariaR.dat" using 1:2 via a,b
plot "TernariaR.dat" using 1:2  title "TernariaR" , Logaritmico(x)
set terminal pdf
set output "TernariaR.pdf" 
replot
pause 5"Pulsa Enter para continuar..."