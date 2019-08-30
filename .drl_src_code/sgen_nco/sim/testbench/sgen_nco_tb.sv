// -------------------------------------------------------------------
// Copyright (C) 2019 Ahmed Shahein
// -------------------------------------------------------------------
`timescale 1us/1ns
`include "defines.sv"
`define ABS(X) (X)<(0)?(-X):(X)
// -------------------------------------------------------------------
module sgen_nco_tb;
  time CLK_PERIOD = 50.0;// 10kHz   
  
  reg       i_rst_an;
  reg       i_ena;
  reg       i_clk;
  reg       s_clk;
  
  reg [`P_PHASEACCU_WIDTH-1:0] i_fcw;
  wire                 rdy;
  wire signed [`P_ROM_WIDTH:0] o_sin_rtl,o_cos_rtl;
  reg                             data_ready;
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
  reg signed [`P_ROM_WIDTH:0]     o_sin_mat,  o_cos_mat;
  // WRITE-OUT RTL RESPONSE FILE  
  reg [8*64:1]                    filename_rtl_oup;
  integer                         fid_rtl_oup;
  integer                         status_rtl_oup;  
  // RTL MATLAB TOLERANCE
  integer diff, abs_diff;
// -------------------------------------------------------------------    
  initial
    begin
           i_rst_an = 1'b1;
      #1   i_rst_an = 1'b0;
      #(2*2*CLK_PERIOD+CLK_PERIOD-3) i_rst_an = 1'b1;
    end
  
  initial
    begin
           i_ena = 1'b0;
      #(2*2*CLK_PERIOD+CLK_PERIOD-1) i_ena = 1'b1;
    end
  
  initial s_clk = 1'b0;
  always s_clk = #(CLK_PERIOD) ~s_clk;
  
  //initial s_clk = #5 i_clk;
  
  assign #1 i_clk =  s_clk;
  
  initial
    begin: TEXTIO_READ_IN
      $display("### INFO: RTL Simulation of NCO.");
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
        status_mat_inp = $fscanf(fid_mat_inp,"%d\n", i_fcw);
      else
        i_fcw = 'd0;
	
      if ($feof(fid_mat_inp)) begin
        data_ready = 1'b1;
      end
    end
  
  always @(posedge i_clk)
    begin: MATLAB_RESPONSE
      if (i_rst_an && i_ena)
        status_mat_oup = $fscanf(fid_mat_oup,"%d %d\n", o_sin_mat, o_cos_mat);
    end

  always @(negedge i_clk)
    begin: ASSERT_RTL_vs_MATLAB
      if (i_rst_an && i_ena)
        diff     = o_sin_rtl - o_sin_mat; 
	abs_diff = `ABS(diff);
	if ( abs_diff > 1)
	  begin 
	    $error("### RTL = %d, MAT = %d", o_sin_rtl, o_sin_mat); error_count<= error_count + 1;
	  end
    end

  `ifdef RTL
    initial
      begin: TEXTIO_WRITE_OUT 
        $sformat(filename_rtl_oup,"%s%0d%s","./sim/testcases/response/response_tc_",`TESTCASE,"_rtl.dat");
        fid_rtl_oup = $fopen(filename_rtl_oup, "w");
        @(posedge data_ready)  $fclose(fid_rtl_oup);
      end
    
    always @(posedge i_clk)
      begin: RTL_RESPONSE
        $fwrite(fid_rtl_oup,"%d\n",o_sin_rtl);
      end
  `endif
  
  sgen_nco #(
    .gp_rom_width  	 (`P_ROM_WIDTH),
    .gp_rom_depth  	 (`P_ROM_DEPTH),
    .gp_phase_accu_width (`P_PHASEACCU_WIDTH)
  ) dut (
    .i_rst_an (i_rst_an),
    .i_ena    (i_ena),
    .i_clk    (i_clk),
    .i_fcw    (i_fcw),
    .o_sin    (o_sin_rtl),
    .o_cos    (o_cos_rtl)
  );

  `ifdef VCD
    initial
       begin
         $sformat(filename_vcd,"%s%0d%s","sgen_nco_",`TESTCASE,".vcd");
         $dumpfile(filename_vcd);
         $dumpvars(0,sgen_nco_tb);
       end
  `endif
          
endmodule
