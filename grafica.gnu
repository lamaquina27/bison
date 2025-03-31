set title "Tiempo de ejecución del parser en Bison"
set xlabel "Ejemplo"
set ylabel "Tiempo (segundos)"
set grid
set term pngcairo
set output "tiempos.png"

plot "tiempos.dat" using 1:2 with linespoints title "Tiempo de Ejecución" lc rgb "#FF0000" pointtype 7 pointsize 1.5

set output
