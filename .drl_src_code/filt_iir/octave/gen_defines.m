function gen_defines(defines)
  filename = strcat("defines_",num2str(defines.testcase),".sv");
  fid = fopen(filename, "w");
  
  fprintf(fid, "`define P_INP_W \t%d\n",defines.gp_inp_width);
  fprintf(fid, "`define P_OUP_W \t%d\n",defines.gp_oup_width);
  fprintf(fid, "`define P_FF_COEFF_L \t%d\n",defines.gp_feedforward_coeff_length);
  fprintf(fid, "`define P_FF_COEFF_W \t%d\n",defines.gp_feedforward_coeff_width);
  fprintf(fid, "`define P_FB_COEFF_L \t%d\n",defines.gp_feedback_coeff_length);
  fprintf(fid, "`define P_FB_COEFF_W \t%d\n",defines.gp_feedback_coeff_width);
  fprintf(fid, "`define P_TOPOLOGY \t%d\n",defines.gp_topology);
  fprintf(fid, "\n");
  fprintf(fid, "`define TESTCASE\t%d\n",defines.testcase);
  fprintf(fid, "\n");
  fprintf(fid, "`define NULL \t0");
  
  fclose(fid);
  cmd = strcat("mv defines_",num2str(defines.testcase),".sv ../sim/testcases/stimuli/");
  system(cmd);