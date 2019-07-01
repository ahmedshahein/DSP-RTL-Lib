clear
clc

param.gp_rom_width        = 8;
param.gp_rom_depth        = 8;
param.gp_phase_accu_width = 16;
param.ampl                = 1;
param.offset              = 0;
param.phase               = 0;
param.fo                  = 150;
param.fs                  = 10e3;
param.nr_of_samples       = 2^16;
param.NFFT                = 2^12;

data = nco(param);
gen_sinusoidal_rom(param)
8*6.02 - 5.76
fcw = floor((param.fo/param.fs)*2^param.gp_phase_accu_width)
