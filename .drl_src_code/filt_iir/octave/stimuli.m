close all
clear
clc  

  nr_samples  = 2^3;
  DEBUG       = '1';
  QUANTIZE    = '';

  N  = 2           % Filter order
  fc = 100;        % Hz cutoff freq
  fs = 1000;       % Hz sample freq
  [b,a] = butter_synth(N,fc,fs);
b=[10 20 30];
a = [1 50 20];
  gp_inp_width		            = 8;
  gp_oup_width		            = 16;
  gp_feedforward_coeff_length = length(b);
  gp_feedforward_coeff_width  = 8;
  gp_feedback_coeff_length    = length(a);
  gp_feedback_coeff_width     = 8;
  gp_topology		              = 1;

if a(1) != 1
  b = b./a(1);
  a = a./a(1);
  %a = [a(1) -a(2:end)];
end

  %b   = b./max(b);
  %a   = a./max(a);
  if QUANTIZE
  q_b = quantize(b, gp_feedforward_coeff_width, "midtread", "signed");
  q_a = quantize(a, gp_feedback_coeff_width, "midtread", "signed");
else
  q_b = b;
  q_a = a;
  end
##  q_a_rtl = [1 -q_a(2:end)];
##  %b   = round( (2^(gp_feedforward_coeff_width-1)-1) * q_b);  
##  %a   = round( (2^(gp_feedback_coeff_width-1)-1) * q_a);
##  if a(1) == 1
##    q_a_rtl = q_a;
##  else
##    q_a_rtl = [1 -q_a(2:end)];
##  endif
  

##  b = [11 25 37];
##  a = [1 -20 -30];
##  q_b = b;
##  q_a = a;
##  q_a_rtl = a;
  
  switch (gp_topology)
    case 0
      topology = 'dfi';
    case 1
      topology = 'dfii';
    case 2
      topology = 'tfii';
    otherwise
      disp("### ERROR: Wrong topology.");
  endswitch
  
  for i = 1 : 10,
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
      data = 0:2^(gp_inp_width-1)-1;
    
    case {4}
      data = 2^(gp_inp_width-1)-1:-1:-2^(gp_inp_width-1);    
      
    case {5}
      fs = 1e3;
      f1 = 1;
      f2 = fs/2;
      t  = 1:1/fs:5;
      data = chirp (t, f1, 5, f2, "logarithmic");
      q_data = quantize(data, gp_inp_width, "midtread", "signed");
      data = round( 2^(gp_inp_width-1) * q_data );
      
    case {6}
      rand ("state", 42);
      r_min = -2^(gp_inp_width-1);
      r_max =  2^(gp_inp_width-1);
      r     = floor(r_min + (r_max - r_min)*rand(1, nr_samples));
      data  = r;
    
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
  case {10}
    data = 0:15;
  endswitch

  %% INPUT STRUCT
  disp("### INFO: Generating defines files.");
  defines.gp_inp_width		            = gp_inp_width;
  defines.gp_oup_width		            = gp_oup_width;
  defines.gp_feedforward_coeff_length = gp_feedforward_coeff_length;
  defines.gp_feedforward_coeff_width  = gp_feedforward_coeff_width;
  defines.gp_feedback_coeff_length    = gp_feedback_coeff_length;
  defines.gp_feedback_coeff_width     = gp_feedback_coeff_width;
  defines.gp_topology                 = gp_topology;
  defines.testcase                    = testcase;
  gen_defines(defines);
  %% COEFFICIENT GENERATION
  %b   = round( (2^(gp_feedforward_coeff_width-1)) * q_b);
  %a   = round( (2^(gp_feedback_coeff_width-1)) * q_a);
  gen_coeffs(b,a,gp_feedforward_coeff_width,gp_feedback_coeff_width);
  %% RESPONSE GENERATION
  octave_data = data;
%  yy          = filter(b,a_rtl,octave_data);
%  q_yy = quantize(yy, gp_oup_width, "midtread", "signed");
%  q_yy = round( (2^(gp_oup_width-1)-1) * yy);
  %[iir_dfi_oup y_ref] = filt_iir (b,a_rtl,data,DEBUG,'topology');
  [iir_oup y_ref] = filt_iir (q_b,q_a,data,DEBUG,topology);
  q_y_ref     = round( (2^(gp_oup_width-1)) * y_ref);
  q_iir_oup   = round( (2^(gp_oup_width-1)) * iir_oup);
  if (q_y_ref == q_iir_oup)
    disp("### INFO: Generating response files.");
    filename_oup = strcat("response_tc_",num2str(testcase,"%d"),"_mat.dat");
    dlmwrite(filename_oup,q_iir_oup,"\n");
    %% STIMULI GENERATION  
    disp("### INFO: Generating stimuli files.");
    filename_inp = strcat("stimuli_tc_",num2str(testcase,"%d"),"_mat.dat");
    dlmwrite(filename_inp,data,"\n");
  else
    disp("### ERROR: Failing test-case.");
  end
end
disp("### INFO: Moving stimuli and response files.");
system("mv stimuli_tc_*.dat ../sim/testcases/stimuli/");
system("mv response_tc_*.dat ../sim/testcases/response/");
system("mv iir_coeff.v ../rtl/");
%% EOF
