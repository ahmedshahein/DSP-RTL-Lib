function gen_sinusoidal_rom(param)
  
ROM_ADDR_WIDTH  = param.gp_rom_depth-3;
ROM_DEPTH       = 2^ROM_ADDR_WIDTH;
ROM_WIDTH       = param.gp_rom_width;

A               = param.ampl;
Offset          = param.offset;
Phase           = param.phase;

fo              = param.fo;
fs              = param.fs;

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