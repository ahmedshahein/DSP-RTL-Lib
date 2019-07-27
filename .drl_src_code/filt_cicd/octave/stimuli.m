  close all
  clear
  clc  

  nr_samples = 2^12;
  
  gp_decimation_factor  = 17;
  gp_order              = 8;
  gp_diff_delay         = 1;
  gp_phase              = 3;
  gp_inp_width          = 2;
  gp_oup_width          = gp_inp_width + gp_order*ceil(log2(gp_decimation_factor*gp_diff_delay));
  
  %G = % 0.5->1
  BG = gp_order * ceil(log2(gp_decimation_factor*gp_diff_delay)) + gp_inp_width
  SF = 2^(gp_order*ceil(log2(gp_decimation_factor*gp_diff_delay)))/((gp_decimation_factor*gp_diff_delay)^gp_order) %[1; 2)
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
      %data(data==2^(gp_inp_width-1)) = 2^(gp_inp_width-1)-1;
      
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
      %nr_samples = 2^12;
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
  defines.gp_decimation_factor  = gp_decimation_factor;
  defines.gp_order              = gp_order;
  defines.gp_diff_delay         = gp_diff_delay;
  defines.gp_phase              = gp_phase;
  defines.gp_inp_width          = gp_inp_width;
  defines.gp_oup_width          = gp_oup_width;
  defines.testcase              = testcase;
  gen_defines(defines);
  %% RESPONSE GENERATION
  octave_data=data;
%  f = cicdesign(gp_decimation_factor, gp_order, gp_diff_delay);
%  yy = cicfilter(f, octave_data, gp_phase);
  
  [yy Hcic] = CICFilter(gp_diff_delay, gp_order, gp_decimation_factor, gp_phase, 1, octave_data);
%  if (yy == FilteredData)
%    disp("###INFO: PASSED");
%  else
%    disp("### INFO: FAILED");
%  end
  
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
%% EOF
