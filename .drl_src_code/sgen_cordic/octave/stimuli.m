close all
clear
clc

defines.gp_mode_rot_vec            = 0;
defines.gp_impl_unrolled_iterative = 1;
defines.gp_nr_iter                 = 12;
defines.gp_angle_width             = 16;
defines.gp_angle_depth             = 24;
defines.gp_xy_width                = 24;
defines.gp_z_width                 = 16;
defines.gp_gain_width              = 24;

for i = 1 : 9,
    testcase = i;
    defines.testcase = testcase;
    printf("### INFO: Running test-case %d\n", testcase);
  switch (testcase)
    case {1}
        x = 1;
        y = 0;
        z = 12*pi/180;
        
     case {2}
        x = 1;
        y = 0;
        z = -12*pi/180; 
        
    case {3}
        defines.gp_mode_rot_vec            = 0;

        x = 1;
        y = 0;
        z = 12*pi/180;
        
     case {4}
        defines.gp_mode_rot_vec            = 0;

        x = 1;
        y = 0;
        z = -12*pi/180;  
 
     case {5} 
       defines.gp_impl_unrolled_iterative = 1;
       
        x = 1;
        y = 0;
        z = 12*pi/180;    
        
     case {6}
        defines.gp_mode_rot_vec            = 1;
        defines.gp_impl_unrolled_iterative = 0;
        defines.gp_nr_iter                 = 24;
        defines.gp_xy_width                = 16;
        defines.gp_z_width                 = 16;
        defines.gp_gain_width              = 16;
        
        x = 1;
        y = 0;
        z = 63*pi/180;  
        
     case {7}
        defines.gp_mode_rot_vec            = 0;
        defines.gp_impl_unrolled_iterative = 0;
        defines.gp_nr_iter                 = 24;
        defines.gp_xy_width                = 16;
        defines.gp_z_width                 = 16;
        defines.gp_gain_width              = 16;
        
        x = 0.5;
        y = 0.5;
        z = 90*pi/180;       
     
    case {8}   
        x = 1;
        y = 1;
        z = 180*pi/180;   
      
    case {9}
        x = 1;
        y = 0;
        z = 200*pi/180; 
        
  endswitch
  %% INPUT STRUCT
  disp("### INFO: Generating defines files.");
  gen_defines(defines);
  %% RESPONSE GENERATION  
  [oup, dbg] = cordic(defines, 
                      x, y, z);  
  disp("### INFO: Generating response files.");
  %% STIMULI GENERATION  
  disp("### INFO: Generating stimuli files.");
endfor
disp("### INFO: Moving stimuli and response files.");
system("mv stimuli_tc_*.dat ../sim/testcases/stimuli/");
system("mv response_tc_*.dat ../sim/testcases/response/");
system("mv atan_lut.v ../rtl/");
%% EOF
