open_project sobel -reset
set_top sobel
add_files sobel/ex.png
add_files sobel/sobel.cpp
add_files sobel/sobel.h
add_files -tb sobel/testbench.cpp
open_solution "solution1"
set_part {xc7z020clg400-1}
create_clock -period 10 -name default
csim_design
csynth_design
export_design -format ip_catalog -description "Custome HLS IP, Sobel filter acceletarion"
exit

