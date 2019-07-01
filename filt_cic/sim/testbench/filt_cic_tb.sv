// -------------------------------------------------------------------
// Copyright (C) 2019 Ahmed Shahein
// -------------------------------------------------------------------
`timescale 1ns/1ps
`include "defines.sv"
// -------------------------------------------------------------------
module filt_cic_tb;
  time CLK_PERIOD = 50;
  
  reg       i_rst_an;
  reg       i_ena;
  reg       i_clk;
  reg       s_clk;
  
  reg [`P_INP_DATA_W-1:0] i_data;
  wire                 rdy;
  wire signed [`P_OUP_DATA_W-1:0] oup_data;
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
  reg signed [`P_OUP_DATA_W-1:0]       o_data_mat;
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
  
  initial assign s_clk = dut.w_sclk;
  initial
    begin: TEXTIO_READ_IN
      $display("### INFO: RTL Simulation of FIR Filter.");
      $display("### Testcase %d", `TESTCASE);
      $write("### ");$system($sformatf("date"));
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
        i_data = 'd0;
	
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
    end
      
  filt_cic #(
    .gp_decimation_factor (`P_DECIMATION),  
    .gp_order		  (`P_ORDER),
    .gp_diff_delay	  (`P_DIFF_DELAY),
    .gp_phase		  (`P_PHASE),
    .gp_inp_width	  (`P_INP_DATA_W),
    .gp_oup_width	  ()
  ) dut (
    .i_rst_an (i_rst_an),
    .i_ena    (i_ena),
    .i_clk    (i_clk),
    .i_data   (i_data),
    .o_data   (oup_data)
  );
    
endmodule
