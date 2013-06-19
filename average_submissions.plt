set term postscript eps enhanced color

set ylabel "Average submissions/10 days"

set xdata time
set timefmt "%Y-%m-%d"
set format x "%Y-%m-%d"
set xtics out rotate by 90
set xtics offset 0.0,-5.0
set bmargin 7
unset key
set output "avg_submissions.eps"
plot "average_submissions.txt" using 1:2 axes x1y1 with linespoints
