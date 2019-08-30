# DSP-RTL-Lib
_**RTL Verilog library for standard DSP modules**_

## Overview
I am delighted and keen to share my passion towards Digital Signal Processing (DSP) with other passionates and learners. I am grateful to the open source community and to my professors, instructors, and colleagues who helped me through the last decade and a half to learn and fall in love with DSP.

I have been focusing on the hardware side of DSP, in particular front-end or RTL design and implementation. Nevertheless, I have digested Matlab/Octave and SystemC sufficient enough to model the developed DSP components, models and even systems as well. I am aiming for a mix-and-match (M&M) approach for this DSP library. As an example, to implement a digital-front-end (DFE) which requires a mixer, decimation stage, and channel selection modules, the DSP RTL Library (DRL) provides all the basic components “hopefully one day” which allows the designer to pick, mix and match them to create a functioning system.

I have very ambitious plans for the DSP RTL Library (DRL), and I hope to meet them all, if not alone may be with your appreciated help and support. I am looking forward to provide the most commonly used DSP components in generic parameterizable and synthesizable RTL code which can be used for either ASIC and/or FPGA development. Moreover, I am planning to provide a GRM “mostly Octave”. The purpose of these models to be used for bit-true verification and building time-lossly systems. I have a wish to validate these modules on an FPGA, but I am a bit sceptical on that point due to time constraints. I am aiming to develop scripts which will take design parameters and generate the RTL. This is planned once the library is alpha release, i.e. stable and mature enough.

The DRL will provide synthesized RTL developed in Verilog 2001, test-bench developed in SystemVerilog 2012, and Octave golden reference models (GRM).

The developed RTL is a conventional implementation, i.e. it is neither area nor power optimized. I have various ideas and thoughts regarding area, power, and latency optimization. However, these approaches are usually application or project specific. Therefore, I didn’t publish any of them at this stage. Nevertheless, if needed do not hesitate to contact me.

## List of Abbreviations
Abbreviation | Description
-------------|:------------
FIR |Finite Impulse Response
IIR |Infinite Impulse Response
CIC | Cascade Integrator Comb
MAC | Multiply ACCumulator
TF | Transposed-Form
DF | Direct-Form
PPD | PolyPhase Decimation
PPI | PolyPhase Interpolation
NCO | Numerically Controlled Oscillator
CORDIC | COordinate Rotation DIgital Computer
LFSR | Linear Feedback Shift Register
RTL | Register Transfer Logic
DSP | Digital Signal Processing
DRL | DSP RTL Library

## List of Modules

Module | Description | Status
-------|-------------|-------
FIR | | Stable
MAC | | Stable
CIC | | Stable
PPD | | Stable
PPI | | Stable
DC | | Planned
IIR | | Planned
NCO | | Stable
CORDIC | | Stable

## Coding Style
I recommend the following coding style which I used during the development of the DRL. The coding style is proposed to facilitate debugging and troubleshooting during both functional and formal verification. Therefore, please, stick to it!

* Asynchronous active low reset
* Synchronous active high enable
* Rising edge flip-flops are only used
* Arithmetic computations are carried out based on fixed-point 2’s complement data type.

## Get Started
1. Make sure that you have the Icarus Verilog installed on your machine.
2. Download the dsp_rtl_lib.sh script individually.
3. Make sure it is executable (ls -la, if it isn't then use chmod +x dsp_rtl_lib.sh).
4. Execute the demo command which will clone the repository, design a CIC decimation filter, and execute a regression verification (./dsp_rtl_lib.sh -demo).

To design a new module (e.g. filt_ppd):
1. cd DSP_RTL_Lib
2. cp .drl_param/filt_ppd_1.param ./
3. nedit filt_ppd_1.param (enter the design configuration values as indicated)
4. ./dsp_rtl_lib.sh -d filt_ppd_1.param

## Folder Structure
The folder structure for each designed module is as follow (e.g. filt_ppd)

- filt_ppd
  |_ log
  |_ octave
  |_ rtl
  |_ sim
    |_testbench
    |_ testcases
      |_ response
      |_ stimuli
  |_ vcd
  |_ vvp
