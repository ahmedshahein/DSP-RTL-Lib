function gen_defines(defines)
  filename = strcat("defines_",num2str(defines.testcase),".sv");
  fid = fopen(filename, "w");
  
  fprintf(fid, "`define P_INP_DATA_W \t%d\n",defines.p_data_width);
  fprintf(fid, "`define P_COEFF_L \t%d\n",defines.p_coeff_length);
  fprintf(fid, "`define P_COEFF_W \t%d\n",defines.p_coeff_width);
  fprintf(fid, "`define P_TF_DF \t%d\n",defines.p_tf_df);
  fprintf(fid, "`define P_SYMM \t\t%d\n",defines.p_symm);
  fprintf(fid, "`define P_OUP_DATA_W \t%d\n",defines.p_data_width+defines.p_coeff_width+defines.p_coeff_length);
  fprintf(fid, "\n");
  fprintf(fid, "`define TESTCASE\t%d\n",defines.testcase);
  fprintf(fid, "\n");
  fprintf(fid, "`define NULL \t0");
  
  fclose(fid);
  cmd = strcat("mv defines_",num2str(defines.testcase),".sv ../sim/testcases/stimuli/");
  system(cmd);