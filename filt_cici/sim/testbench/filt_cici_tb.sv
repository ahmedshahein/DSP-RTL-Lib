// -------------------------------------------------------------------
// Copyright (C) 2019 Ahmed Shahein
// -------------------------------------------------------------------
`timescale 1ns/1ps
`include "defines.sv"
// -------------------------------------------------------------------
module filt_cici_tb;
  time CLK_PERIOD = 400;
  time F_CLK_PERIOD = CLK_PERIOD/`P_INTERPOLATION;
  
  reg       i_rst_an;
  reg       i_ena=1'b0;
  reg       i_clk=1'b0;
  reg       i_fclk=1'b0;
  reg       f_clk=1'b0;
  reg       s_clk;
  int       r_cnt=`P_INTERPOLATION;
  
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
    begin: RST
                        i_rst_an = 1'b1;
      #2                i_rst_an = 1'b0;
      #(0.5*CLK_PERIOD) i_rst_an = 1'b1;
    end

  always @(posedge i_clk) 
    begin: EGU
      if (i_rst_an)
      i_ena = 1'b1;
    end
  
  //initial i_clk = 1'b0;
  always
    begin
      f_clk = #(F_CLK_PERIOD/2) ~f_clk;
    end

  always @(posedge f_clk)
    begin: SCLK
      if (r_cnt<`P_INTERPOLATION-1)
        r_cnt <= r_cnt + 1;
      else
        r_cnt <= 'd0;
	
      i_clk <= s_clk;
    end
  assign s_clk = (r_cnt<`P_INTERPOLATION/2) ? 1'b1 : 1'b0;   
//always i_clk = #2 s_clk;
always i_fclk = #2 f_clk;

  initial
    begin: TEXTIO_READ_IN
      $display("### INFO: RTL Simulation of CIC Interpolation Filter.");
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
  
  always @(posedge i_fclk)
    begin: MATLAB_RESPONSE
      if (i_rst_an && i_ena)
        status_mat_oup = $fscanf(fid_mat_oup,"%d\n", o_data_mat);
    end

  always @(negedge f_clk)
    begin
      if (i_rst_an && i_ena)
        assert (oup_data == o_data_mat) 
	else
	  begin 
	    $error("### RTL = %d, MAT = %d", oup_data, o_data_mat); error_count<= error_count + 1;
	  end
    end
      
  filt_cici #(
    .gp_interpolation_factor (`P_INTERPOLATION),  
    .gp_order		  (`P_ORDER),
    .gp_diff_delay	  (`P_DIFF_DELAY),
    .gp_phase		  (`P_PHASE),
    .gp_inp_width	  (`P_INP_DATA_W),
    .gp_oup_width	  ()
  ) dut (
    .i_rst_an (i_rst_an),
    .i_ena    (i_ena),
    .i_clk    (i_clk),
    .i_fclk   (f_clk),
    .i_data   (i_data),
    .o_data   (oup_data)
  );
    
endmodule
