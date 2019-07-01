// -------------------------------------------------------------------
// Copyright (C) 2019 Ahmed Shahein
// -------------------------------------------------------------------
`timescale 1ns/1ps
//`include "defines.sv"
//`define LOG2(X) (X<2) ? 0 : (1+LOG2(X>>1))
//$floor($log10(MAX_COUNT)/$log10(2));
// -------------------------------------------------------------------
module sgen_cordic_tb;
  function automatic int log2(int x);
    if (x < 2)
      log2 = 0;
    else
      log2 = log2(x>>1) + 1;
  endfunction
  
  time CLK_PERIOD = 50;
  
  reg       i_rst_an;
  reg       i_ena;
  reg       i_clk;
  reg       s_clk;
  
 // reg [`P_INP_DATA_W-1:0] i_data;
  wire                 rdy;
  //wire signed [`P_OUP_DATA_W-1:0] oup_data;
  reg                             data_ready;
  integer error_count=0;
  // READ-IN MATLAB STIMULI FILE  
  reg [8*64:1]                    filename_mat_inp;
  integer                         fid_mat_inp;
  integer                         status_mat_inp;  
  // READ-IN MATLAB RESPONSE FILE
  reg [8*64:1]                    filename_mat_oup;
  integer                         fid_mat_oup;
  integer                         status_mat_oup;
  //reg signed [`P_OUP_DATA_W-1:0]       o_data_mat;
// -------------------------------------------------------------------    

  initial
    begin
           i_rst_an = 1'b1;
      #170 i_rst_an = 1'b0;
      #205 i_rst_an = 1'b1;
    end
  
  initial
    begin
           i_ena = 1'b0;
      #400 i_ena = 1'b1;
    end
  
  initial i_clk = 1'b0;
  always i_clk = #(CLK_PERIOD) ~i_clk;
  
  initial
    begin
      $display("### log2(%d) = %d",  4, log2(4)+1);
      $display("### log2(%d) = %d",  8, log2(8)+1);
      $display("### log2(%d) = %d",  9, log2(9)+1);
      $display("### log2(%d) = %d", 15, log2(15)+1);
      $display("### log2(%d) = %d", 16, log2(16)+1);      
    end
 /* initial assign s_clk = dut.w_sclk;
  initial
    begin: TEXTIO_READ_IN
      $display("### INFO: RTL Simulation of FIR Filter.");
      $display("### Testcase %d", `TESTCASE);
      $write("### ");
      $system($sformatf("date"));
      $sformat(filename_mat_inp,"%s%0d%s","./sim/testcases/stimuli/stimuli_tc_",`TESTCASE,"_mat.dat");
      $sformat(filename_mat_oup,"%s%0d%s","./sim/testcases/response/response_tc_",`TESTCASE,"_mat.dat");
      $display("%s",filename_mat_inp);
      fid_mat_inp = $fopen(filename_mat_inp, "r");
      fid_mat_oup = $fopen(filename_mat_oup, "r");
      if ((fid_mat_inp == `NULL)||(fid_mat_oup == `NULL)) begin
        $display("data_file handle was NULL");
        $finish;
      end
      
      @(posedge data_ready) 
        begin 
	  $fclose(fid_mat_inp); 
	  $fclose(fid_mat_oup); 

	  if (error_count>0)
            $display("### INFO: Testcase FAILED");
          else
            $display("### INFO: Testcase PASSED");
	    
  	  $finish; 
	end
    end
    
  always @(posedge i_clk)
    begin: MATLAB_STIMULI
      if (i_rst_an && i_ena)
        status_mat_inp = $fscanf(fid_mat_inp,"%d\n", i_data);
      else
        i_data = AMPd0;
	
      if ($feof(fid_mat_inp)) begin
        data_ready = 1'b1;
      end
    end
  
  always @(negedge s_clk)
    begin: MATLAB_RESPONSE
      if (i_rst_an && i_ena)
        status_mat_oup = $fscanf(fid_mat_oup,"%d\n", o_data_mat);
    end

  always @(negedge s_clk)
    begin
      if (i_rst_an && i_ena)
        assert (oup_data == o_data_mat) 
	else
	  begin 
	    $error("### RTL = %d, MAT = %d", oup_data, o_data_mat); error_count<= error_count + 1;
	  end
    end*/
      
  sgen_cordic #(
    .gp_mode_rot_vec	        (1),
    .gp_impl_unrolled_iterative (1),
    .gp_nr_iter 	        (12),
    .gp_angle_width	        (16),
    .gp_angle_depth             (12),
    .gp_xy_width	        (24),
    .gp_z_width 	        (16)
  ) dut (
    .i_rst_an(i_rst_an),
    .i_ena(i_ena),
    .i_clk(i_clk),
    .i_x('d4194304), //('d2097152),
    .i_y('d0),       //('d2097152),
    .i_z('sd20016),
    .o_x(),
    .o_y(),
    .o_z(),
    .o_done()
  );
    
endmodule
