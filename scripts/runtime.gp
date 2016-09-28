reset
set ylabel 'time(sec)'
set style fill transparent solid 0.35
set title 'clz perfomance'
set term png enhanced font 'Verdana,11'
set output 'runtime.png'

plot [:][0:0.0000003]'txt_recursive.txt' using 1:5 with points title 'recursive', \
'txt_harley_algorighm.txt' using 1:5 with points title 'harley', \
'txt_iteration.txt' using 1:5 with points title 'iteration', \
'txt_byte_shift.txt' using 1:5 with points title 'byte shift', \
'txt_binary_search.txt' using 1:5 with points title 'binary search'
