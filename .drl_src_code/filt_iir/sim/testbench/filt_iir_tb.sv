// -------------------------------------------------------------------
// Copyright (C) 2019 Ahmed Shahein
// -------------------------------------------------------------------
`timescale 1ns/1ps
//`include "defines.sv"
// -------------------------------------------------------------------
module filt_iir_tb;
  time CLK_PERIOD = 50;
  
  reg	    i_rst_an;
  reg	    i_ena;
  reg	    i_clk;
  reg	    s_clk;
  reg [8-1:0] i_data;
  //reg [`P_INP_DATA_W-1:0] i_data;
  wire  	       rdy;
  //wire signed [`P_OUP_DATA_W-1:0] oup_data;
  reg				  data_ready;
  integer error_count=0;
  // READ-IN MATLAB STIMULI FILE  
  reg [8*64:1]  		  filename_mat_inp;
  integer			  fid_mat_inp;
  integer			  status_mat_inp;  
  // READ-IN MATLAB RESPONSE FILE
  reg [8*64:1]  		  filename_mat_oup;
  integer			  fid_mat_oup;
  integer			  status_mat_oup;
  //reg signed [`P_OUP_DATA_W-1:0]       o_data_mat;
  
class debug #(int unsigned array_size = 57, int unsigned element_size = 19);
  static function void print_debug_bus (signed [array_size-1:0] array, input integer nr_of_elements, input string msg="");

  for (int i=0; i<nr_of_elements; i++)
    begin
      $display("### INFO: Debug for %s ... At time %t value = %d", msg, $time, $signed(array[i*element_size +: element_size]));
    end
  endfunction
endclass  
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
      #410 i_ena = 1'b1;
    end
  
  initial i_clk = 1'b0;
  always i_clk = #(CLK_PERIOD) ~i_clk;

  initial
    begin
      i_data = 8'sd0;
      #500 i_data = 8'sd1;
      #100 i_data = 8'sd2;
      #100 i_data = 8'sd3;
      #100 i_data = 8'sd4;
      #100 i_data = 8'sd5;
      #100 i_data = 8'sd6;
      #100 i_data = 8'sd7;
      #100 i_data = 8'sd8;
      #100 i_data = 8'sd9;      
      #1000 $finish;
    end

  always @(posedge i_clk)
    begin
      //debug #(16,8)::print_debug_bus(dut.feedforward_delayline, 2, "DLY");
      //debug #(48,16)::print_debug_bus(dut.feedforward_mul, 3, "MUL");$display("input ... %d",i_data);
      //debug #(57,19)::print_debug_bus(dut.feedforward_add, 3, "ADD");$display("input ... %d",i_data);
      //debug #(38,19)::print_debug_bus(dut.feedback_delayline, 2, "DLY");
      //debug #(54,27)::print_debug_bus(dut.feedback_mul, 2, "MUL");
      //debug #(90,30)::print_debug_bus(dut.feedback_add, 3, "ADD");
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
      
  filt_iir #(
    .gp_inp_width		 (8),   
    .gp_oup_width		 (30),
    .gp_feedforward_coeff_length (3),
    .gp_feedforward_coeff_width  (8),
    .gp_feedback_coeff_length	 (3),
    .gp_feedback_coeff_width	 (8),
    .gp_topology		 (2)
  ) dut (
    .i_rst_an (i_rst_an),
    .i_ena    (i_ena),
    .i_clk    (i_clk),
    .i_data   (i_data),
    .o_data   (oup_data)
  );
    
endmodule
