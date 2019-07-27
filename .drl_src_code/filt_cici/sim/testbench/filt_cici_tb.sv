// -------------------------------------------------------------------
// Copyright (C) 2019 Ahmed Shahein
// -------------------------------------------------------------------
`timescale 1ns/1ps
`include "defines.sv"
// -------------------------------------------------------------------
module filt_cici_tb;
  time CLK_PERIOD = 400;
  //time F_CLK_PERIOD = CLK_PERIOD/`P_INTERPOLATION;
  
  reg       i_rst_an;
  reg       i_ena=1'b0;
  reg       i_clk=1'b0;
  reg       i_fclk=1'b0;
  reg       f_clk=1'b0;
  reg       s_clk;
  int       r_cnt=`P_INTERPOLATION;
  
  reg [`P_INP_DATA_W-1:0] i_data,r_data;
  wire                 rdy;
  wire signed [`P_OUP_DATA_W-1:0] oup_data;
  reg                             data_ready=1'b0;
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
  reg signed [`P_OUP_DATA_W-1:0]  o_data_mat;
// -------------------------------------------------------------------    
  initial
    begin: RST
                        i_rst_an = 1'b1;
      #2                i_rst_an = 1'b0;
      #(0.5*CLK_PERIOD) i_rst_an = 1'b1;
    end

  always @(posedge s_clk) 
    begin: EGU
      if (i_rst_an)
      i_ena = 1'b1;
    end
  
  always f_clk = #(CLK_PERIOD/(`P_INTERPOLATION*2)) ~f_clk;
  
  always @(posedge f_clk)
    begin: SCLK
      if (r_cnt<`P_INTERPOLATION-1)
        r_cnt <= r_cnt + 1;
      else
        r_cnt <= 'd0;
    end
  assign s_clk = (r_cnt<`P_INTERPOLATION/2) ? 1'b1 : 1'b0;   
 
 initial begin
    fork
        forever #2 i_fclk = f_clk;
        forever #2 i_clk = s_clk;
    join 
 end

  initial
    begin: TEXTIO_READ_IN
      $display("### INFO: RTL Simulation of CIC Interpolation Filter.");
      $display("### Testcase %d", `TESTCASE);
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
        if (oup_data != o_data_mat)
	  begin 
	    $error("### RTL = %d, MAT = %d", oup_data, o_data_mat); error_count<= error_count + 1;
	  end
    end
      
  filt_cici #(
    .gp_interpolation_factor (`P_INTERPOLATION),  
    .gp_order		     (`P_ORDER),
    .gp_diff_delay	     (`P_DIFF_DELAY),
    .gp_phase		     (`P_PHASE),
    .gp_inp_width	     (`P_INP_DATA_W),
    .gp_oup_width	     (`P_OUP_DATA_W)
  ) dut (
    .i_rst_an (i_rst_an),
    .i_ena    (i_ena),
    .i_clk    (s_clk),
    .i_fclk   (i_fclk),
    .i_data   (i_data),
    .o_data   (oup_data)
  );

`ifdef VCD
  initial
     begin
       $sformat(filename_vcd,"%s%0d%s","filt_cici_",`TESTCASE,".vcd");
       $dumpfile(filename_vcd);
       $dumpvars(0,filt_cici_tb);
     end
`endif
    
endmodule
