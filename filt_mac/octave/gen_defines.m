function gen_defines(defines)
  filename = strcat("defines_",num2str(defines.testcase),".sv");
  fid = fopen(filename, "w");
  
  fprintf(fid, "`define P_INP_DATA_W \t%d\n",defines.gp_data_width);
  fprintf(fid, "`define P_COEFF_L \t%d\n",defines.gp_coeff_length);
  fprintf(fid, "`define P_COEFF_W \t%d\n",defines.gp_coeff_width);
  fprintf(fid, "`define P_SYMM \t\t%d\n",defines.gp_symm);
  fprintf(fid, "`define P_OUP_DATA_W \t%d\n",defines.gp_data_width+defines.gp_coeff_width+defines.gp_coeff_length);
  fprintf(fid, "\n");
  fprintf(fid, "`define TESTCASE\t%d\n",defines.testcase);
  fprintf(fid, "\n");
  fprintf(fid, "`define DIV2(N) ((N/2)+(N%%2))\n");
  fprintf(fid, "\n");
  fprintf(fid, "`define NULL \t0");
  
  fclose(fid);
  cmd = strcat("mv defines_",num2str(defines.testcase),".sv ../sim/testcases/stimuli/");
  system(cmd);