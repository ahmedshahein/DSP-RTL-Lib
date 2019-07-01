#!/bin/bash

export PRJ_DIR=$PWD
export RTL_DIR=${PRJ_DIR}/rtl
export SIM_DIR=${PRJ_DIR}/sim

RTL_FILES="\
  ${RTL_DIR}/dff.v \
  ${RTL_DIR}/shift_register.v \
  ${RTL_DIR}/commutator.v \
  ${RTL_DIR}/mul_add.v \
  ${RTL_DIR}/filt_ppd.v \
"

rm -rf log/*
rm -rf work
vlib work

if [ $1 = "-clean" ]; then
  rm -rf sim/testcase/stimuli/* sim/testcases/response/* log/*
fi

if [ $# = 0 ]; then
  for i in {1..9}; do
    ln -sf ${PRJ_DIR}/sim/testcases/stimuli/defines_${i}.sv ${PRJ_DIR}/sim/testbench/defines.sv
  
    vlog $RTL_FILES
    vlog ${SIM_DIR}/testbench/filt_ppd_tb.sv
  
    vsim -logfile ./log/tc_${i}.log work.filt_ppd_tb < modelsim.batch
  done
else
  echo "Simulating testcase " $2
  ln -sf ${PRJ_DIR}/sim/testcases/stimuli/defines_$2.sv ${PRJ_DIR}/sim/testbench/defines.sv
  vlog $RTL_FILES
  vlog ${SIM_DIR}/testbench/filt_ppd_tb.sv
  vsim -logfile ./log/tc_$2.log work.filt_ppd_tb
fi

exit 0

#mkdir -p rtl sim sim/testbench sim/testcases/stimuli sim/testcases/response log
