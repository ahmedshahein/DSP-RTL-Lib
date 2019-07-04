#!/bin/bash

export PRJ_DIR=$PWD
export RTL_DIR=${PRJ_DIR}/rtl
export SIM_DIR=${PRJ_DIR}/sim

RTL_FILES="\
  ${RTL_DIR}/dff.v \
  ${RTL_DIR}/shift_register.v \
  ${RTL_DIR}/commutator.v \
  ${RTL_DIR}/mul_add.v \
  ${RTL_DIR}/filt_ppi.v \
"

rm -rf log/*
rm -rf work
vlib work

if [ $1 = "-clean" ]; then
  echo "### INFO: Clean project folder"
  rm -rf sim/testcase/stimuli/* sim/testcases/response/* log/*
  exit 10
fi

if [ $1 = "-l" ] || [ $1 = "-lint" ]; then
  echo "### INFO: Linting RTL code"
  verilator -I./rtl --top-module mul_add --lint-only rtl/dff.v rtl/shift_register.v rtl/mul_add.v &> log/lint_mul_add.log
  verilator -I./rtl --top-module commutator --lint-only rtl/dff.v rtl/shift_register.v rtl/commutator.v &> log/lint_commutator.log
  verilator -I./rtl --top-module filt_ppi --lint-only rtl/dff.v rtl/shift_register.v rtl/commutator.v rtl/mul_add.v rtl/filt_ppi.v &> log/lint_filt_ppi.log
  exit 20
fi

if [ $# = 0 ]; then
  for i in {1..9}; do
    ln -sf ${PRJ_DIR}/sim/testcases/stimuli/defines_${i}.sv ${PRJ_DIR}/sim/testbench/defines.sv
  
    vlog $RTL_FILES
    vlog ${SIM_DIR}/testbench/filt_ppi_tb.sv
  
    vsim -logfile ./log/tc_${i}.log work.filt_ppi_tb < modelsim.batch
  done
else
  echo "### INFO: Simulating testcase " $2
  ln -sf ${PRJ_DIR}/sim/testcases/stimuli/defines_$2.sv ${PRJ_DIR}/sim/testbench/defines.sv
  vlog $RTL_FILES
  vlog ${SIM_DIR}/testbench/filt_ppi_tb.sv
  vsim -logfile ./log/tc_$2.log work.filt_ppi_tb
fi

exit 0

#mkdir -p rtl sim sim/testbench sim/testcases/stimuli sim/testcases/response log
