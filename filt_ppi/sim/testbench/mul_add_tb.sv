// Code your design here
`define p_row       dut.gp_interpolation_factor
`define p_col       dut.c_col
`define p_mul_oup_w dut.c_mul_out_width
`define p_add_oup_w dut.c_sum_out_width
`define p_reg_oup_w dut.c_reg_out_width

module mul_add_tb;
  time CLK_PERIOD = 50;
  
  reg       i_rst_an;
  reg       i_ena;
  reg       i_clk;
  reg [4*8-1:0] i_data;
  reg       s_clk;
  
  int D = 4;
  
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
  initial s_clk = 1'b0;
  always s_clk = #(CLK_PERIOD*D) ~s_clk;
  initial
    begin
           i_data = 'h00;
      #445 i_data = 'h0A;
      #100 i_data = 'h0B;
      #100 i_data = 'h0C;
      #100 i_data = 'h0D;
      #100 i_data = 'h0E;
      #100 i_data = 'h0F;
      /*i_data='d0;
      #460 i_data = {8'sd5,8'sd5,8'sd5,8'sd5};
      #400 i_data = {8'sd35,8'sd25,8'sd15,8'sd5};
      #400 i_data = {-8'sd120,-8'sd50,-8'sd127,-8'sd3};
      #400 i_data = {-8'sd77,-8'sd39,-8'sd1,-8'sd0};
      #400 i_data = {8'sd0, 8'sd1, 8'sd0, 8'sd0};
      #400 i_data = {8'sd0, 8'sd1, 8'sd1, 8'sd1};
      #400 i_data = {8'sd1, 8'sd1, 8'sd1, 8'sd1};
      #400 i_data = 'hE0;
      #400 i_data = 'hF0;
      #400 i_data = 'hAA;*/
    end
  
  
  static int p_nr_coeff  = dut.gp_coeff_length;
  
  

  int ppd_mul_matrix[][];
  int ppd_add_matrix[][];
  int ppd_reg_matrix[][];
  int z;
  reg [`p_mul_oup_w*`p_row*`p_col-1:0]     r_mul;
  reg [`p_add_oup_w*`p_row*`p_col-1:0]     r_add;
  reg [`p_reg_oup_w*`p_row*(`p_col-1)-1:0] r_reg;
  
  initial
    begin
      $display("PPD coefficient length \t\t\t= %2d", p_nr_coeff);
      $display("PPD coefficient matrix [row][col] \t= [%2d][%2d]", `p_row, `p_col);
      $display("PPD multiplier output width \t\t= %2d", `p_mul_oup_w);
      $display("PPD adder output width \t\t\t= %2d", `p_add_oup_w);
      
      assign r_mul = dut.w_mul;
      assign r_add = dut.w_sum;
      assign r_reg = dut.w_reg;
      
      ppd_mul_matrix = new[`p_row];
      foreach(ppd_mul_matrix[i]) ppd_mul_matrix[i] = new[`p_col];
      
      ppd_add_matrix = new[`p_row];
      foreach(ppd_add_matrix[i]) ppd_add_matrix[i] = new[`p_col];      
      
      ppd_reg_matrix = new[`p_row];
      foreach(ppd_reg_matrix[i]) ppd_reg_matrix[i] = new[`p_col-1];     
    end
  
  always @(i_data)
    begin
      z=0;
      for (int i = 0; i < `p_col; i++) begin
        for (int j = 0; j < `p_row; j++) begin
          ppd_mul_matrix[j][i] = $signed(r_mul[z*`p_mul_oup_w +: `p_mul_oup_w]);           
          $write(" MUL:: ",ppd_mul_matrix[j][i]);
	  z++;
        end
	$display("\n");
      end 
    end

  always @(i_data)
    begin
      z=0;
      for (int i = 0; i < `p_col-1; i++) begin
        for (int j = 0; j < `p_row; j++) begin
          ppd_reg_matrix[j][i] = $signed(r_reg[z*`p_reg_oup_w +: `p_reg_oup_w]);          
          $write(" REG:: ", ppd_reg_matrix[j][i]);
	  z++; 
        end
	$display("\n");
      end
    end
    
  always @(i_data)
    begin
      z=0;
      for (int i = 0; i < `p_col; i++) begin
        for (int j = 0; j < `p_row; j++) begin
          ppd_add_matrix[j][i] = $signed(r_add[z*`p_add_oup_w +: `p_add_oup_w]);          
          $write(" ADD:: ", ppd_add_matrix[j][i]);
	  z++; 
        end
	$display("\n");
      end
    end
        
  mul_add #() dut (
    .i_rst_an (i_rst_an),
    .i_ena    (i_ena),
    .i_clk    (i_clk),
    .i_data   (i_data),
    .o_data   ()
  );
  
  initial
    begin
      $dumpfile("mul_add_tb.vcd");
      $dumpvars;
      #3000;
      $finish;
    end
endmodule
