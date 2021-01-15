  close all
  clear
  clc  

  nr_samples = 2^12;
  
  fs = 5000;
  fp = 2000;
  fc = 2500;
  [n,Wn] = buttord(fp/fs,fc/fs,1,60);
  [b,a] = butter(2,Wn);
  
  gp_inp_width		            = 8;
  gp_oup_width		            = 16;
  gp_feedforward_coeff_length = length(b);
  gp_feedforward_coeff_width  = 8;
  gp_feedback_coeff_length    = length(a);
  gp_feedback_coeff_width     = 8;
  gp_topology		              = 0;

  q_b = quantize(b, gp_feedforward_coeff_width, "midtread", "signed");
  b   = round( (2^(gp_feedforward_coeff_width-1)-1) * q_b);
  q_a = quantize(a, gp_feedback_coeff_width, "midtread", "signed");
  a   = round( (2^(gp_feedback_coeff_width-1)-1) * q_a);
  
  for i = 1 : 9,
    testcase = i;
    printf("### INFO: Running test-case %d\n", testcase);
  switch (testcase)
    case {1}
      nr_samples = 2^8;
      data = zeros(1, nr_samples);
      data(2)   = 1;
      data(100) = 1;
      data(180) = 1;
      data(220) = 1;
      
    case {2}
      nr_samples = 2^8;
      data = ones(1, nr_samples); 
      data(1) = 0;
      data(2) = 0;
      data(100:101) = 0;
      data(180:181) = 0;
      data(220:221) = 0; 
   
    case {3}
      data = -2^(gp_inp_width-1):2^(gp_inp_width-1)-1;
    
    case {4}
      data = 2^(gp_inp_width-1)-1:-1:-2^(gp_inp_width-1);    
      
    case {5}
      fs = 1e3;
      f1 = 1;
      f2 = fs/2;
      t = 1:1/fs:5;
      data = chirp (t, f1, 5, f2, "logarithmic");
      q_data = quantize(data, gp_inp_width, "midtread", "signed");
      data = round( 2^(gp_inp_width-1) * q_data );
      
    case {6}
      rand ("state", 42);
      r_min = -2^(gp_inp_width-1);
      r_max =  2^(gp_inp_width-1);
      r     = floor(r_min + (r_max - r_min)*rand(1, nr_samples));
      data = r;
    
    case {7}
      fs    = 1e3;
      fo    = 113;
      A     = 1;
      phi   = 0;
      dc    = 0;
      c     = 10;
      t     = 0:1/fs:c/fo-1/fs;
      data  = round( 2^(gp_inp_width-1) * (A * sin(2*pi*fo*t + phi) + dc) );
      data(data==2^(gp_inp_width-1)) = 2^(gp_inp_width-1)-1;
  
    case {8}
      fs    = 1e3;
      fo    = 113;
      A     = 1;
      phi   = 0;
      dc    = 0;
      c     = 31;
      t     = 0:1/fs:c/fo-1/fs;
      data  = A * sin(2*pi*fo*t + phi) + dc;
      rand ("state", 72);
      r_min = -1;
      r_max =  1;
      An = 0.2;
      r     = An * ( r_min + (r_max - r_min)*rand(1, length(data)) );
      q_data = quantize(data+r, gp_inp_width, "midtread", "signed");
      data = round( 2^(gp_inp_width-1) * q_data );      
      data(data==2^(gp_inp_width-1)) = 2^(gp_inp_width-1)-1;

    case {9}
      nr_samples = 2^12;
      fs    = 1e3;
      fo    = 173.38943;
      A     = 1;
      phi   = pi/3;
      dc    = 0.1;
      c     = 53;
      t     = 0:1/fs:c/fo-1/fs;
      data  = A * sin(2*pi*fo*t + phi) + dc;
      rand ("state", 1732);
      r_min = -1;
      r_max =  1;
      An = 0.25;
      r     = An * ( r_min + (r_max - r_min)*rand(1, length(data)) );
      q_data = quantize(data+r, gp_inp_width, "midtread", "signed");
      data = round( 2^(gp_inp_width-1) * q_data );      
      data(data==2^(gp_inp_width-1)) = 2^(gp_inp_width-1)-1;
      
  endswitch

  %% INPUT STRUCT
  disp("### INFO: Generating defines files.");
  defines.gp_inp_width		    = gp_inp_width;
  defines.gp_oup_width		    = gp_oup_width;
  defines.gp_feedforward_coeff_length = gp_feedforward_coeff_length;
  defines.gp_feedforward_coeff_width  = gp_feedforward_coeff_width;
  defines.gp_feedback_coeff_length    = gp_feedback_coeff_length;
  defines.gp_feedback_coeff_width     = gp_feedback_coeff_width;
  defines.gp_topology                 = gp_topology;
  defines.testcase            = testcase;
  gen_defines(defines);
  %% COEFFICIENT GENERATION
  gen_coeffs(b,a,gp_feedforward_coeff_width,gp_feedback_coeff_width);
  %% RESPONSE GENERATION
  octave_data=data;
  yy= filter(b,[1 -a(2:end)],octave_data);
  disp("### INFO: Generating response files.");
  filename_oup = strcat("response_tc_",num2str(testcase,"%d"),"_mat.dat");
  dlmwrite(filename_oup,yy,"\n");
  %% STIMULI GENERATION  
  disp("### INFO: Generating stimuli files.");
  filename_inp = strcat("stimuli_tc_",num2str(testcase,"%d"),"_mat.dat");
  dlmwrite(filename_inp,data,"\n");
end
disp("### INFO: Moving stimuli and response files.");
system("mv stimuli_tc_*.dat ../sim/testcases/stimuli/");
system("mv response_tc_*.dat ../sim/testcases/response/");
system("mv iir_coeff.v ../rtl/");
%% EOF