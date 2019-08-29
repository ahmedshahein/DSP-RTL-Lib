  close all
  clear
  clc  

  param.gp_rom_width        = 8;
  param.gp_rom_depth        = 5;
  param.gp_phase_accu_width = 16;
  param.ampl                = 1;
  param.offset              = 0;
  param.phase               = 0;
  
  for i = 1 : 4,
    testcase = i;
    printf("### INFO: Running test-case %d\n", testcase);
  switch (testcase)
    case {1}
      param.fo                  = 150;
      param.fs                  = 10e3;
      param.nr_of_samples       = floor( (param.fs/param.fo)*5 );
      param.NFFT                = floor( log2(param.nr_of_samples) );
      fcw                       = floor( (param.fo/param.fs)*2^param.gp_phase_accu_width );
      
    case {2}
      param.fo                  = 150;
      param.fs                  = 10e3;
      param.nr_of_samples       = 2^16;
      param.NFFT                = 2^10;
      fcw                       = floor( (param.fo/param.fs)*2^param.gp_phase_accu_width );
      
    case {3}
      param.fo                  = 733.33;
      param.fs                  = 10e3;
      param.nr_of_samples       = floor( (param.fs/param.fo)*5 );
      param.NFFT                = floor( log2(param.nr_of_samples) );
      fcw                       = floor( (param.fo/param.fs)*2^param.gp_phase_accu_width );
    
    case {4}
      param.fo                  = 2500;
      param.fs                  = 10e3;
      param.nr_of_samples       = 2^12;
      param.NFFT                = 2^12;
      fcw                       = floor( (param.fo/param.fs)*2^param.gp_phase_accu_width );
      [osin, ocos] = nco(param);
      data1 = [osin' ocos'];
      fcw1 = fcw.*ones(1,length(data1));
      param.fo                  = 333.33;
      fcw                       = floor( (param.fo/param.fs)*2^param.gp_phase_accu_width );
      [osin, ocos] = nco(param);
      data2 = [osin' ocos'];
      fcw2 = fcw.*ones(1,length(data1));
      param.fo                  = 1337;
      fcw                       = floor( (param.fo/param.fs)*2^param.gp_phase_accu_width );
      [osin, ocos] = nco(param);  
      data3 = [osin' ocos'];
      fcw3 = fcw.*ones(1,length(data1));
      ref_data = [data1; data2; data3];    
      ref_fcw = [fcw1 fcw2 fcw3];
      
  endswitch

  %% INPUT STRUCT
  disp("### INFO: Generating defines files.");
  defines.gp_rom_width        = param.gp_rom_width;
  defines.gp_rom_depth        = param.gp_rom_depth-3;
  defines.gp_phase_accu_width = param.gp_phase_accu_width;
  defines.fcw                 = fcw;
  defines.testcase            = testcase;
  gen_defines(defines);
  %% RESPONSE GENERATION
  [osin, ocos] = nco(param);
  if (testcase ~= 4)
    octave_data = [osin' ocos'];
  else
    octave_data = ref_data;
  endif  
  disp("### INFO: Generating response files.");
  filename_oup = strcat("response_tc_",num2str(testcase,"%d"),"_mat.dat");
  dlmwrite(filename_oup,octave_data,'delimiter',' ');
  %% STIMULI GENERATION  
  disp("### INFO: Generating stimuli files.");
  if (testcase ~= 4)
    ref_fcw = fcw.*ones(1,length(octave_data));
  endif 
  
  filename_inp = strcat("stimuli_tc_",num2str(testcase,"%d"),"_mat.dat");
  dlmwrite(filename_inp,ref_fcw,"\n");
  
  gen_sinusoidal_rom(param);
  sin_mem_fname = strcat("nco_sin_rom_",num2str(testcase,"%d"),".v");
  cos_mem_fname = strcat("nco_cos_rom_",num2str(testcase,"%d"),".v");
  movefile('nco_sin_rom.v', sin_mem_fname);
  movefile('nco_cos_rom.v', cos_mem_fname);
end
disp("### INFO: Moving stimuli and response files.");
system("mv stimuli_tc_*.dat ../sim/testcases/stimuli/");
system("mv response_tc_*.dat ../sim/testcases/response/");
system("mv nco_sin_rom_*.v ../sim/testcases/stimuli/");
system("mv nco_cos_rom_*.v ../sim/testcases/stimuli/");
%% EOF
