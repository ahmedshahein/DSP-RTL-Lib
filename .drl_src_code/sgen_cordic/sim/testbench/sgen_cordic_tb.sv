// -------------------------------------------------------------------
// Copyright (C) 2019 Ahmed Shahein
// -------------------------------------------------------------------
`timescale 1ns/1ps
`include "defines.sv"
// -------------------------------------------------------------------
module sgen_cordic_tb;
  
  time F_CLK_PERIOD = 50;
  time S_CLK_PERIOD = 50*`P_ITER;
  
  reg       i_rst_an;
  reg       i_ena;
  reg       i_clk;
  wire      s_clk;
  reg       f_clk;
  reg       data_ready=1'b0;
  integer   counter;
  integer error_count=0;
  reg [8*64:1]                    filename_vcd;
  // READ-IN MATLAB STIMULI FILE  
  reg [8*64:1]                    filename_mat_inp;
  integer                         fid_mat_inp;
  integer                         status_mat_inp;  
  // READ-IN MATLAB RESPONSE FILE
  reg [8*64:1]                    filename_mat_oup;
  integer                         fid_mat_oup;
  integer                         status_mat_oup;
  // READ-IN MATLAB RESPONSE FILE
  reg [8*64:1]                    filename_mat_dbg;
  integer                         fid_mat_dbg;
  integer                         status_mat_dbg;
  // MATLAB DEBUG OUTPUTS
  reg signed [`P_XY_WIDTH+$clog2(`P_ITER)-1:0] o_x_mat; 
  reg signed [`P_XY_WIDTH+$clog2(`P_ITER)-1:0] o_y_mat; 
  reg signed [`P_Z_WIDTH +$clog2(`P_ITER)-1:0] o_z_mat; 
  reg signed [1                            :0] o_d_mat;
  
  reg signed [`P_XY_WIDTH-1:0] i_x;
  reg signed [`P_XY_WIDTH-1:0] i_y;
  reg signed [`P_Z_WIDTH-1 :0] i_z;
  
  reg signed [`P_XY_WIDTH+$clog2(`P_ITER)-1:0] o_x_a_mat;
  reg signed [`P_XY_WIDTH-1:0] o_y_r_mat;//???? change width based on mode of operation
// -------------------------------------------------------------------    

  initial
    begin
                         i_rst_an = 1'b1;
      #1                 i_rst_an = 1'b0;
      #(S_CLK_PERIOD-10) i_rst_an = 1'b1;
    end
  
  initial
    begin
                        i_ena = 1'b0;
      #(S_CLK_PERIOD-1) i_ena = 1'b1;
    end
  
  initial f_clk = 1'b1;
  always f_clk = #(F_CLK_PERIOD) ~f_clk;

  initial counter = 1024;
  always @(posedge f_clk)
    begin
      if (counter < `P_ITER-1)
        counter <= counter + 1;
      else
        counter <= 0;
    end
  assign s_clk = (counter < `P_ITER/2) ? 1'b0 : 1'b1;  
  
  assign #1 i_clk =  (`P_IMPL_U_I) ? s_clk : f_clk;
    
  initial
    begin: TEXTIO_READ_IN
      $display("### INFO: RTL Simulation of FIR Filter.");
      $display("### Testcase %d", `TESTCASE);
      $sformat(filename_mat_inp,"%s%0d%s","./sim/testcases/stimuli/stimuli_tc_",`TESTCASE,"_mat.dat");
      $sformat(filename_mat_oup,"%s%0d%s","./sim/testcases/response/response_tc_",`TESTCASE,"_oup_mat.dat");
      $sformat(filename_mat_dbg,"%s%0d%s","./sim/testcases/response/response_tc_",`TESTCASE,"_dbg_mat.dat");
      fid_mat_inp = $fopen(filename_mat_inp, "r");
      fid_mat_oup = $fopen(filename_mat_oup, "r");
      fid_mat_dbg = $fopen(filename_mat_dbg, "r");
      if ((fid_mat_inp == `NULL)||(fid_mat_oup == `NULL)) begin
        $display("data_file handle was NULL");
        $finish;
      end
      
      @(posedge data_ready) 
        begin 
	  $fclose(fid_mat_inp); 
	  $fclose(fid_mat_oup); 
          $fclose(fid_mat_dbg);
	  
	  if (error_count>0)
            $display("### INFO: Testcase FAILED");
          else
            $display("### INFO: Testcase PASSED");
	    
  	  $finish; 
	end
    end
    
  always @(posedge s_clk)
    begin: MATLAB_STIMULI
      if (i_rst_an && i_ena)
        status_mat_inp = $fscanf(fid_mat_inp,"%d %d %d\n", i_x, i_y, i_z);
    end
  
  always @(negedge s_clk)
    begin: MATLAB_RESPONSE
      if (i_rst_an && i_ena)
        status_mat_oup = $fscanf(fid_mat_oup,"%d %d\n", o_x_a_mat, o_y_r_mat);
    end
    
  always @(negedge f_clk)
    begin: MATLAB_DEBUG
      if (i_rst_an && i_ena)
        status_mat_dbg = $fscanf(fid_mat_dbg,"%d %d %d %d\n", o_x_mat, o_y_mat, o_z_mat, o_d_mat);
      
      if ($feof(fid_mat_dbg)) begin
        data_ready = 1'b1;
      end
    end
    
  wire signed [`P_XY_WIDTH-1:0] x_2_gain; 
  wire signed [`P_XY_WIDTH-1:0] y_2_gain; 
  sgen_cordic #(
    .gp_mode_rot_vec	        (`P_MODE_ROT_VEC),
    .gp_impl_unrolled_iterative (`P_IMPL_U_I),
    .gp_nr_iter 	        (`P_ITER),
    .gp_angle_width	        (`P_ATAN_LUT_WIDTH),
    .gp_angle_depth             (`P_ATAN_LUT_DEPTH),
    .gp_xy_width	        (`P_XY_WIDTH),
    .gp_z_width 	        (`P_Z_WIDTH)
  ) dut (
    .i_rst_an(i_rst_an),
    .i_ena(i_ena),
    .i_clk(i_clk),
    .i_x(i_x),
    .i_y(i_y), 
    .i_z(i_z),
    .o_x(x_2_gain),
    .o_y(y_2_gain),
    .o_z(),
    .o_done()
  );

  cordic_gain #(
    .gp_mode_rot_vec (`P_MODE_ROT_VEC),
    .gp_gain_width   (`P_ATAN_GAIN_WIDTH),
    .gp_xy_width     (`P_XY_WIDTH),
    .gp_xy_owidth    ()
  ) gain_compensation (
    .i_cordic_x (x_2_gain),
    .i_cordic_y (y_2_gain),
    .o_cordic_x (),
    .o_cordic_y ()
  );
  
`ifdef VCD
  initial
     begin
       $sformat(filename_vcd,"%s%0d%s","sgen_cordic_",`TESTCASE,".vcd");
       $dumpfile(filename_vcd);
       $dumpvars(0,sgen_cordic_tb);
     end
`endif
    
endmodule
