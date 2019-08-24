// -------------------------------------------------------------------
// Copyright (C) 2019 Ahmed Shahein
// -------------------------------------------------------------------
`timescale 1ns/1ps
`include "defines.sv"
// -------------------------------------------------------------------
module filt_mac_tb;
  localparam CLK_CYCLES = (`P_SYMM) ? `DIV2(`P_COEFF_L) : `P_COEFF_L;
  time F_CLK_PERIOD = 50;
  time S_CLK_PERIOD = 50*CLK_CYCLES;
  
  reg       i_rst_an;
  reg       i_ena;
  reg       i_clk;
  reg       s_clk;
  reg       f_clk = 1'b0;
  
  reg [`P_INP_DATA_W-1:0] i_data;
  wire                 rdy;
  wire signed [`P_OUP_DATA_W-1:0] oup_data;
  wire                            o_done;
  reg                             data_ready;
  reg                             load_response= 1'b0;
  integer error_count=0;
  integer count_clk_cycles=127;
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
    begin: RGU
           i_rst_an = 1'b1;
      #17  i_rst_an = 1'b0;
      #205 i_rst_an = 1'b1;
    end
  
  initial
    begin: EGU
           i_ena = 1'b0;
      #400 i_ena = 1'b1;
    end
  
  //initial f_clk = 1'b0;
  always 
    begin: FCGU
      f_clk = #(F_CLK_PERIOD) ~f_clk; 
    end
    
  initial s_clk = 1'b0;
  //initial count_clk_cycles = 127;
  always @(posedge f_clk)
    begin: CLK_DIV
      if (i_ena)
        begin
	  if (count_clk_cycles < CLK_CYCLES-1)
            count_clk_cycles <= count_clk_cycles + 1'b1;
	  else
	    count_clk_cycles = 0;
	end
    end  
  
  always @(*) 
    begin: SCGU
      s_clk = (count_clk_cycles==0) ? 1'b1 : 1'b0;
    end
    
  always
    begin: CGU
      i_clk = #1 f_clk;
    end
    
  //initial load_response = 1'b0;
  always @(posedge o_done)
    begin
      if ( (i_rst_an && i_ena) && (load_response < 1) )
      load_response <= load_response + 1'b1;
    end
      
  initial
    begin: TEXTIO_READ_IN
      $display("### INFO: RTL Simulation of FIR Filter.");
      $display("### Testcase %d", `TESTCASE);
      $write("### ");
      //$system($sformatf("date"));
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
    
  always @(posedge s_clk)
    begin: MATLAB_STIMULI
      if (i_rst_an && i_ena)
        status_mat_inp = $fscanf(fid_mat_inp,"%d\n", i_data);
      else
        i_data = 'd0;
	
      if ($feof(fid_mat_inp)) begin
        data_ready = 1'b1;
      end
    end
  
  always @(posedge s_clk)
    begin: MATLAB_RESPONSE
      if (i_rst_an && i_ena && load_response)
        status_mat_oup = $fscanf(fid_mat_oup,"%d\n", o_data_mat);
      else
        o_data_mat = 'd0;
    end

  always @(negedge s_clk)
    begin: CHK_OUP
      if (i_rst_an && i_ena)
        if (oup_data != o_data_mat)
	  begin 
	    $error("### RTL = %d, MAT = %d", oup_data, o_data_mat); error_count<= error_count + 1;
	  end
    end
  
  /*initial
    begin
      i_data = 'd0;
      #(549+300) i_data = 'd1;
      #(4*100) i_data = 'd0;
      
      i_data = 'd0;
      #(549+300) i_data = 'd1;
      
      i_data = 'd10;
      #(549+300) i_data = 'd1;
      #(4*100)   i_data = 'd2; 
      #(4*100)   i_data = 'd3;    
      #(4*100)   i_data = 'd4; 
      #(4*100)   i_data = 'd5; 
      #(4*100)   i_data = 'd6; 
      #(4*100)   i_data = 'd7;    
      #(4*100)   i_data = 'd8; 
      #(4*100)   i_data = 'd9;  
      
      i_data = 'd0;
      #(549+1700) i_data = 'd1;
      #(17*100)   i_data = 'd2; 
      #(17*100)   i_data = 'd3;    
      #(17*100)   i_data = 'd4; 
      #(17*100)   i_data = 'd5; 
      #(17*100)   i_data = 'd6; 
      #(17*100)   i_data = 'd7;    
      #(17*100)   i_data = 'd8; 
      #(17*100)   i_data = 'd9;                      
    end*/
      
  filt_mac #(
    .gp_inp_width    (`P_INP_DATA_W),
    .gp_coeff_length (`P_COEFF_L),
    .gp_coeff_width  (`P_COEFF_W),
    .gp_symm	     (`P_SYMM),
    .gp_oup_width    (`P_OUP_DATA_W)
  ) dut (
    .i_rst_an (i_rst_an),
    .i_ena    (i_ena),
    .i_clk    (i_clk),
    .i_data   (i_data),
    .o_data   (oup_data),
    .o_done   (o_done)
  );

`ifdef VCD
  initial
     begin
       $sformat(filename_vcd,"%s%0d%s","filt_mac_",`TESTCASE,".vcd");
       $dumpfile(filename_vcd);
       $dumpvars(0,filt_mac_tb);
     end
`endif
    
endmodule
