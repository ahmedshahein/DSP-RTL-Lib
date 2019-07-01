function gen_defines(defines)
  filename = strcat("defines_",num2str(defines.testcase),".sv");
  fid = fopen(filename, "w");
  
  fprintf(fid, "`define P_DECIMATION \t%d\n",defines.gp_decimation_factor);
  fprintf(fid, "`define P_ORDER \t%d\n",defines.gp_order);
  fprintf(fid, "`define P_DIFF_DELAY \t%d\n",defines.gp_diff_delay);
  fprintf(fid, "`define P_PHASE \t%d\n",defines.gp_phase);
  fprintf(fid, "`define P_INP_DATA_W \t%d\n",defines.gp_inp_width);
  fprintf(fid, "`define P_OUP_DATA_W \t%d\n",defines.gp_oup_width);
  fprintf(fid, "\n");
  fprintf(fid, "`define TESTCASE\t%d\n",defines.testcase);
  fprintf(fid, "\n");
  fprintf(fid, "`define NULL \t0");
  
  fclose(fid);
  cmd = strcat("mv defines_",num2str(defines.testcase),".sv ../sim/testcases/stimuli/");
  system(cmd);