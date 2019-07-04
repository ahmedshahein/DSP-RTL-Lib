// -------------------------------------------------------------------
// Copyright (C) 2019 Ahmed Shahein
// -------------------------------------------------------------------
// 
// -------------------------------------------------------------------
module commutator_tb;
  time CLK_PERIOD = 50;
  
  reg       i_rst_an;
  reg       i_ena;
  reg       i_clk;
  reg f_clk;
  reg [4*4-1:0] i_data;
  
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
  initial f_clk = 1'b0;
  always f_clk = #(CLK_PERIOD/4) ~f_clk;  
  
  initial
    begin
           i_data = 'h0000;
      #400 i_data = 'hABCD;   
      #100 i_data = 'hDCBA;
      #100 i_data = 'h1234;
      #100 i_data = 'h4321;
     /* #100 i_data = 'h0E;
      #100 i_data = 'h0F;
      #100 i_data = 'hA0;
      #100 i_data = 'hB0;
      #100 i_data = 'hC0;
      #100 i_data = 'hD0;
      #100 i_data = 'hE0;
      #100 i_data = 'hF0;
      #100 i_data = 'hAA;*/
    end
  
  commutator #() dut (
    .i_rst_an (i_rst_an),
    .i_ena    (i_ena),
    .i_clk    (f_clk),
    .i_data   (i_data),
    .o_data   (),
    .o_clk    ()
  );
  
  initial
    begin
      $dumpfile("commutator_tb.vcd");
      $dumpvars;
      #30000;
      $finish;
    end
endmodule
