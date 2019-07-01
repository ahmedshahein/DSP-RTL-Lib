#!/bin/bash

if [ ! -d rtl ]; then
  mkdir rtl
fi

if [ ! -d sim ]; then
  mkdir -p sim/testbench sim/testcases/stimuli sim/testcases/response
fi

if [ ! -d octave ]; then
  mkdir octave
fi

if [ ! -d log ]; then
  mkdir log
fi
