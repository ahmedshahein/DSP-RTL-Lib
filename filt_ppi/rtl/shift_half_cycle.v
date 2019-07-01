// -------------------------------------------------------------------
// Copyright (C) 2019 Ahmed Shahein
// -------------------------------------------------------------------
// 
// -------------------------------------------------------------------
module shift_half_cycle #(
  parameter gp_data_width = 8
) (
  input  wire                     i_rst_an,  // Asynchronous active low reset
  input  wire                     i_ena,     // Synchronous active high enable
  input  wire                     i_clk,     // Rising-edge clock
  input  wire [gp_data_width-1:0] i_data,    // Input data with gp_idata_width bits MSB:LSB, signed
  output wire [gp_data_width-1:0] o_data     // Unsigned data with gp_decimation_factor x gp_idata_width width MSB:LSB 
);
// -------------------------------------------------------------------
reg [gp_data_width-1:0] r_dly;
// -------------------------------------------------------------------

  always @(negedge i_clk or negedge i_rst_an)
    begin
      if (!i_rst_an)
        r_dly <= 'd0;
      else if (i_ena)
        r_dly <= i_data;
    end
    
  assign o_data = r_dly;
      
endmodule
