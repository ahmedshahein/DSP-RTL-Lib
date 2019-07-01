// -------------------------------------------------------------------
// Copyright (C) 2019 Ahmed Shahein
// -------------------------------------------------------------------
//
// -------------------------------------------------------------------
module nco #(
  parameter gp_inp_width   = 8,  // ROM address bit-width
  parameter gp_oup_width   = 16
) (
  input  wire                           i_rst_an,
  input  wire                           i_ena,
  input  wire                           i_clk,
  input  wire        [gp_inp_width-1:0] i_fata,
  output wire signed [gp_oup_width-1:0] o_data
);
// -------------------------------------------------------------------
  // CONSTANT DECLARATION
  localparam c_rom_depth = ;
  // REGISTER DECLARATION
  reg        [gp_xxx-1:0] r_xxx;
  // WIRE DECLARATION
  wire signed [c_xxx-1:0] w_xxx;
// -------------------------------------------------------------------
  `include "xxx.v"
// -------------------------------------------------------------------
  always @(posedge i_clk or negedge i_rst_an)
    begin: p_<xxx>
      if (!i_rst_an)
        begin
	  
	end
      else if (i_ena)
        begin
	  
	end
    end
  
  assign w_xxx = w_xxx + w_xxx>>2;
   
  always @(*)
    begin: p_<xxx>
      case (xxx)
        0:
	default:
      endcase
    end
        
endmodule
