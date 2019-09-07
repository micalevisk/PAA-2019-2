#!/bin/bash
## https://github.com/micalevisk/LPAV-2017-1/blob/master/TP10_TP11/src/lib/plotMediasExercicio.sh#L60
  ## http://seismic.yonsei.ac.kr/gnu_intro.html

## https://alvinalexander.com/technology/gnuplot-charts-graphs-examples
gnuplot <<- EOF
set title 'BP and Heartrate'
set term png
set output "image.png"
set grid

set yrange [50:160]
set xlabel 'time (military)'

set label 'finished walk' at 15, 140
unset label
set label 'finished walk' at 15, 105

plot 'bp-hr.dat' u 1:2 w lp t 'systolic', 'bp-hr.dat' u 1:3 w lp t 'diastolic', 'bp-hr.dat' u 1:4 w lp t 'heartrate'
EOF
