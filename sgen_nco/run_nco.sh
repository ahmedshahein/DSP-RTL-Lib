#!/bin/bash

export PRJ_DIR=$PWD
export RTL_DIR=${PRJ_DIR}/rtl
export SIM_DIR=${PRJ_DIR}/sim

RTL_FILES="\
  ${RTL_DIR}/sgen_nco.v \
"

rm -rf log/*
rm -rf work
vlib work

if [ $1 = "-clean" ]; then
  rm -rf sim/testcase/stimuli/* sim/testcases/response/* log/*
fi

if [ $# = 0 ]; then
  for i in {1..4}; do
    ln -sf ${PRJ_DIR}/sim/testcases/stimuli/defines_${i}.sv ${PRJ_DIR}/sim/testbench/defines.sv
    ln -sf ${PRJ_DIR}/sim/testcases/stimuli/nco_sin_rom_${i}.v ${PRJ_DIR}/rtl/nco_sim_rom.v
    ln -sf ${PRJ_DIR}/sim/testcases/stimuli/nco_cos_rom_${i}.v ${PRJ_DIR}/rtl/nco_cos_rom.v
  
    vlog $RTL_FILES
    vlog ${SIM_DIR}/testbench/sgen_nco_tb.sv
  
    vsim -logfile ./log/tc_${i}.log work.sgen_nco_tb < modelsim.batch
  done
else
  echo "Simulating testcase " $2
  ln -sf ${PRJ_DIR}/sim/testcases/stimuli/defines_$2.sv ${PRJ_DIR}/sim/testbench/defines.sv
  ln -sf ${PRJ_DIR}/sim/testcases/stimuli/nco_sin_rom_$2.v ${PRJ_DIR}/rtl/nco_sin_rom.v
  ln -sf ${PRJ_DIR}/sim/testcases/stimuli/nco_cos_rom_$2.v ${PRJ_DIR}/rtl/nco_cos_rom.v
    
  vlog $RTL_FILES
  vlog ${SIM_DIR}/testbench/sgen_nco_tb.sv
  vsim -logfile ./log/tc_$2.log work.sgen_nco_tb
fi

exit 0

#mkdir -p rtl sim sim/testbench sim/testcases/stimuli sim/testcases/response log
