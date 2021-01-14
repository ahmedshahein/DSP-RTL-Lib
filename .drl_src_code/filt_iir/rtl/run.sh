vlib work
vlog -work work -stats=none dff.v filt_iir.v ../sim/testbench/filt_iir_tb.sv
vsim work.filt_iir_tb
