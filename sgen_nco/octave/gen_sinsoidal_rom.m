close all
clear
clc

ROM_ADDR_WIDTH  = 5;
ROM_DEPTH       = 2^ROM_ADDR_WIDTH;
ROM_WIDTH       = 8;

A               = 1;
Offset          = 0;
Phase           = 0;

fo              = 50;
fs              = 1e3;
PA_WIDTH        = 16;

fcw = round( (fo/fs) * 2^PA_WIDTH );

sin_samples = A * sin( (pi/4) * [0:ROM_DEPTH-1]./ROM_DEPTH + Phase) + Offset;
cos_samples = A * cos( (pi/4) * [0:ROM_DEPTH-1]./ROM_DEPTH + Phase) + Offset;
sin_max     = A * sin( pi/4 + Phase) + Offset;
cos_max     = A * cos( pi/4 + Phase) + Offset;

sin_samples_int = round( (2^ROM_WIDTH-1) * sin_samples );
cos_samples_int = round( (2^ROM_WIDTH-1) * cos_samples );
sin_max_int     = round( (2^ROM_WIDTH-1) * sin_max );
cos_max_int     = round( (2^ROM_WIDTH-1) * cos_max );

fid_sin = fopen("nco_sin_rom.v", "w");
fid_cos = fopen("nco_cos_rom.v", "w");

for i = 1 : ROM_DEPTH
  fprintf(fid_sin, "assign nco_sin_rom[%d] = %d;\n", i-1, sin_samples_int(i));
  fprintf(fid_cos, "assign nco_cos_rom[%d] = %d;\n", i-1, cos_samples_int(i));
endfor
fprintf(fid_sin, "assign nco_sin_max = %d;\n", sin_max_int);
fprintf(fid_cos, "assign nco_cos_max = %d;\n", cos_max_int);

fclose(fid_sin);
fclose(fid_cos);

system("mv nco_sin_rom.v nco_cos_rom.v ../rtl");

testcase = 1;

defines.p_rom_width        = ROM_WIDTH;
defines.p_rom_depth        = ROM_ADDR_WIDTH;
defines.p_phase_accu_width = PA_WIDTH;
defines.testcase           = testcase;
gen_defines(defines)



n = 2^9;
phase_accu(1) = 0;
for i = 2 : n
  if (phase_accu(i-1) <= (2^PA_WIDTH-1))
    phase_accu(i) = phase_accu(i-1) + fcw;
  else
    phase_accu(i) = phase_accu(i-1) - (2^PA_WIDTH-1);
  endif
endfor

pa_bin    = dec2bin(phase_accu,PA_WIDTH);
addr_bin  = pa_bin(:,4:4+ROM_ADDR_WIDTH-1);
addr_dec  = bin2dec(addr_bin);

%%
ROM_DEPTH = 8*ROM_DEPTH;
sin_samples = A * sin( (2*pi) * [0:ROM_DEPTH-1]./ROM_DEPTH + Phase) + Offset;
cos_samples = A * cos( (2*pi) * [0:ROM_DEPTH-1]./ROM_DEPTH + Phase) + Offset;

sin_samples_ref = round( (2^ROM_WIDTH-1) * sin_samples );
cos_samples_ref = round( (2^ROM_WIDTH-1) * cos_samples );

sin_nco = sin_samples_ref(addr_dec+1);