// -------------------------------------------------------------------
// Copyright (C) 2019 Ahmed Shahein
// -------------------------------------------------------------------
//
// -------------------------------------------------------------------
`timescale 1ns/1ps
`include "defines.sv"
// -------------------------------------------------------------------
module filt_ppd_tb;
  time CLK_PERIOD = 50;
  
  reg       i_rst_an;
  reg       i_ena=1'b0;
  reg       i_clk;
  reg f_clk=1'b0;
  wire      s_clk;// = 1'b0;
  
  integer error_count=0;
  
  reg                             data_ready;
  reg  signed [`P_INP_DATA_W-1:0] i_data,r_data;
  wire signed [`P_OUP_W-1:0]      o_data_rtl;
  reg [8*64:1]                    filename_vcd;
  // READ-IN MATLAB STIMULI FILE  
  reg [8*64:1]                    filename_mat_inp;
  integer                         fid_mat_inp;
  integer                         status_mat_inp;  
  // READ-IN MATLAB RESPONSE FILE
  reg [8*64:1]                    filename_mat_oup;
  integer                         fid_mat_oup;
  integer                         status_mat_oup;
  reg signed [`P_OUP_W-1:0]       o_data_mat;
// -------------------------------------------------------------------    
  initial
    begin: RGU
           i_rst_an = 1'b1;
      #130 i_rst_an = 1'b0;
      #205 i_rst_an = 1'b1;
    end
  
  always @(posedge f_clk) 
    begin: EGU
      if (i_rst_an&&!s_clk)
      i_ena = 1'b1;
    end
  
  always
    begin: GEN_CLK
      f_clk = #(CLK_PERIOD/2) ~f_clk;
    end
    reg res_clk;
  initial begin
   fork
     forever #2 i_clk = f_clk;
     forever #1 res_clk = s_clk;
   join
  end
    
  initial data_ready = 0;

  initial
    begin: TEXTIO_READ_IN
      $display("### INFO: RTL Simulation of Polyphase Decimation FIR Filter.");
      $display("### Testcase %d", `TESTCASE);
      //$write("### ");$system($sformatf("date"));
      $sformat(filename_mat_inp,"%s%0d%s","./sim/testcases/stimuli/stimuli_tc_",`TESTCASE,"_mat.dat");
      $sformat(filename_mat_oup,"%s%0d%s","./sim/testcases/response/response_tc_",`TESTCASE,"_mat.dat");
      $display("%s",filename_mat_inp);$display("%s",filename_mat_oup);
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
        status_mat_inp = $fscanf(fid_mat_inp,"%d\n", r_data);
      else
        r_data = 'd0;
	
      if ($feof(fid_mat_inp)) begin
        data_ready = 1'b1;
      end
    end
  always i_data = #5 r_data;
  always @(posedge res_clk)
    begin: MATLAB_RESPONSE
      if (i_rst_an && i_ena)
        status_mat_oup = $fscanf(fid_mat_oup, "%d\n", o_data_mat);
    end
 
  filt_ppd #(
    .gp_idata_width       (`P_INP_DATA_W ),  
    .gp_decimation_factor (`P_DECIMATION ),
    .gp_coeff_length      (`P_COEFF_L    ),
    .gp_coeff_width       (`P_COEFF_W    ),
    .gp_tf_df	          (`P_TF_DF      ),
    .gp_comm_reg_oup	  (`P_COMM_R_OUP ),
    .gp_comm_ccw          (`P_COMM_CCW_CW),
    .gp_mul_ccw           (`P_MUL_CCW_CW ),
    .gp_comm_phase	  (`P_COMM_PHA   ),
    .gp_odata_width       (              )
  ) dut (
    .i_rst_an (i_rst_an  ),
    .i_ena    (i_ena     ),
    .i_clk    (i_clk     ),
    .i_data   (i_data    ),
    .o_data   (o_data_rtl),
    .o_sclk   (s_clk     )
  );

  always @(negedge s_clk)
    begin
      if (i_rst_an && i_ena)
        if (o_data_rtl != o_data_mat) 
	//else
	  begin 
	    $error("### RTL = %d, MAT = %d", o_data_rtl, o_data_mat); error_count<= error_count + 1;
	  end
    end
                  
`ifdef VCD
  initial
     begin
       $sformat(filename_vcd,"%s%0d%s","filt_ppd_",`TESTCASE,".vcd");
       $dumpfile(filename_vcd);
       $dumpvars(0,filt_ppd_tb);
     end
`endif
    
endmodule
//iverilog -o ppd -g2x filt_ppd_tb.sv commutator.v mul_add.v filt_ppd.v
//vvp ppd
