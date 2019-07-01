// -------------------------------------------------------------------
// Copyright (C) 2019 Ahmed Shahein
// -------------------------------------------------------------------
//
// -------------------------------------------------------------------
`timescale 1ns/1ps
`include "defines.sv"
// -------------------------------------------------------------------
module filt_ppi_tb;
  time CLK_PERIOD = 50;
  
  reg       i_rst_an;
  reg       i_ena;
  wire       i_clk;
  reg       f_clk=1'b0;
  reg      s_clk = 1'b0;
  int r_cnt='d0;
  
  integer error_count=0;
  
  reg                             data_ready;
  reg  signed [`P_INP_DATA_W-1:0] i_data;
  wire signed [`P_OUP_W-1:0]      o_data_rtl;
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
    begin: GEN_RST
           i_rst_an = 1'b1;
      #170 i_rst_an = 1'b0;
      #205 i_rst_an = 1'b1;
    end
  
  initial
    begin: GEN_ENA
           i_ena = 1'b0;
      #460 i_ena = 1'b1;
    end
  
  /*initial i_clk = 1'b0;
  always
    begin: GEN_CLK
      i_clk = #(CLK_PERIOD) ~i_clk;
    end*/
  
  initial f_clk = 1'b0;
  always f_clk = #(CLK_PERIOD/`P_INTERPOLATION) ~f_clk;
  
  always @(posedge f_clk)
    begin
      if (r_cnt<`P_INTERPOLATION-1)
        r_cnt <= r_cnt + 1;
      else
        r_cnt <= 'd0;
    end
 assign i_clk = (r_cnt<`P_INTERPOLATION/2) ? 1'b1 : 1'b0;   
 
  initial data_ready = 0;

  initial
    begin: TEXTIO_READ_IN
      $display("### INFO: RTL Simulation of Polyphase Interpolation FIR Filter.");
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
  
  always @(posedge f_clk)
    begin: MATLAB_RESPONSE
      if (i_rst_an && i_ena)
        status_mat_oup = $fscanf(fid_mat_oup,"%d\n", o_data_mat);
    end
 
  filt_ppi #(
    .gp_idata_width       (`P_INP_DATA_W ),  
    .gp_interpolation_factor (`P_INTERPOLATION),
    .gp_coeff_length      (`P_COEFF_L    ),
    .gp_coeff_width       (`P_COEFF_W    ),
    .gp_tf_df	          (`P_TF_DF      ),
//    .gp_comm_reg_oup	  (`P_COMM_R_OUP ),
    .gp_comm_ccw          (`P_COMM_CCW_CW),
    .gp_mul_ccw           (`P_MUL_CCW_CW ),
    .gp_comm_phase	  (`P_COMM_PHA   ),
    .gp_odata_width       (              )
  ) dut (
    .i_rst_an (i_rst_an  ),
    .i_ena    (i_ena     ),
    .i_clk    (i_clk     ),
    .i_data   (i_data    ),
    .i_fclk   (f_clk     ),
    .o_data   (o_data_rtl),
    .o_sclk   (     )
  );
  
  `define P_COL dut.ppi_mul_add.c_col
  `define P_ROW `P_INTERPOLATION
  int z;
  reg [`P_INTERPOLATION*`P_OUP_W-1:0]     r_mul;
  
  initial assign s_clk = dut.w_sclk;
  initial assign r_mul = dut.mul_add_2_comm;
  
  always @(posedge s_clk)
    begin
      z=0;
      for (int i = 0; i < `P_COL; i++) begin
        for (int j = 0; j < `P_ROW; j++) begin          
          $write(" MUL:: ", $signed(r_mul[z*`P_OUP_W +: `P_OUP_W]));
	  z++;
        end
	$display("\n");
      end 
    end
    
  always @(negedge s_clk)
    begin
      if (i_rst_an && i_ena)
        assert (o_data_rtl == o_data_mat) 
	else
	  begin 
	    $error("### RTL = %d, MAT = %d", o_data_rtl, o_data_mat); error_count<= error_count + 1;
	  end
    end
                  
  /*initial
    begin
      $dumpfile("filt_ppd_tb.vcd");
      $dumpvars;
      #3000;
      $finish;
    end*/
    
endmodule
//iverilog -o ppd -g2x filt_ppd_tb.sv commutator.v mul_add.v filt_ppd.v
//vvp ppd
