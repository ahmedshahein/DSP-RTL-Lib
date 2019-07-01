function gen_defines(defines)
  filename = strcat("defines_",num2str(defines.testcase),".sv");
  fid = fopen(filename, "w");
  
  fprintf(fid, "`define P_ROM_WIDTH \t\t%d\n",defines.gp_rom_width);
  fprintf(fid, "`define P_ROM_DEPTH \t\t%d\n",defines.gp_rom_depth);
  fprintf(fid, "`define P_PHASEACCU_WIDTH \t%d\n",defines.gp_phase_accu_width);
  fprintf(fid, "\n");
  fprintf(fid, "`define TESTCASE\t\t%d\n",defines.testcase);
  fprintf(fid, "\n");
  fprintf(fid, "`define NULL \t0");
  
  fclose(fid);
  cmd = strcat("mv defines_",num2str(defines.testcase),".sv ../sim/testcases/stimuli/");
  system(cmd);