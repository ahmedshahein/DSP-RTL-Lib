// -------------------------------------------------------------------
// Copyright (C) 2019 Ahmed Shahein
// -------------------------------------------------------------------
//
// -------------------------------------------------------------------
`timescale 1ns/1ps
`include "defines.sv"
// -------------------------------------------------------------------
module filt_ppi_tb;
  time CLK_PERIOD = 1000;
  time F_CLK_PERIOD = CLK_PERIOD/`P_INTERPOLATION;
  
  reg       i_rst_an;
  reg       i_ena=1'b0;
  reg       i_clk;
  reg       i_fclk;
  reg       f_clk=1'b0;
  reg       s_clk;
  int       r_cnt=`P_INTERPOLATION;
  reg [1:0] r_start_chk='d0;
  integer   error_count=0;
  
  reg                             data_ready=1'b0;
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
  reg  signed [`P_OUP_W-1:0]      r_data_mat;
  reg  signed [`P_OUP_W-1:0]      sr_data_mat [0:`P_INTERPOLATION];
  reg  signed [`P_OUP_W-1:0]      o_data_mat;
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
  
  always f_clk = #(F_CLK_PERIOD/2) ~f_clk;
  
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
        forever #2 i_clk  = s_clk;
    join 
 end

    
  always @(posedge i_clk)
    begin: FLAG_START_CHK
      if (r_start_chk < 3)
        r_start_chk <= r_start_chk + 1;
    end

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
  
  always @(posedge i_fclk)
    begin: MATLAB_RESPONSE
      if (i_rst_an && i_ena)
        status_mat_oup = $fscanf(fid_mat_oup,"%d\n", o_data_mat);
    end
 
  filt_ppi #(
    .gp_idata_width          (`P_INP_DATA_W   ),  
    .gp_interpolation_factor (`P_INTERPOLATION),
    .gp_coeff_length         (`P_COEFF_L      ),
    .gp_coeff_width          (`P_COEFF_W      ),
    .gp_tf_df	             (`P_TF_DF        ),
    .gp_comm_ccw             (`P_COMM_CCW_CW  ),
    .gp_mul_ccw              (`P_MUL_CCW_CW   ),
    .gp_comm_phase	     (`P_COMM_PHA     ),
    .gp_odata_width          (`P_OUP_W        )
  ) dut (
    .i_rst_an (i_rst_an  ),
    .i_ena    (i_ena     ),
    .i_clk    (i_clk     ),
    .i_data   (i_data    ),
    .i_fclk   (i_fclk     ),
    .o_data   (o_data_rtl),
    .o_sclk   (          )
  );
    
  always @(negedge f_clk)
    begin: ASSERT_OUP_CHK
      if (i_rst_an && i_ena && (r_start_chk == 3))
        assert (o_data_rtl == o_data_mat) 
	else
	  begin 
	    $error("### RTL = %d, MAT = %d", o_data_rtl, o_data_mat); error_count<= error_count + 1;
	  end
    end
    
endmodule
