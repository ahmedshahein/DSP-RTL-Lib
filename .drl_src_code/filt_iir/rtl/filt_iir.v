// -------------------------------------------------------------------
// Copyright (C) 2019 Ahmed Shahein
// -------------------------------------------------------------------
//
// -------------------------------------------------------------------
module filt_iir #(
  parameter gp_inp_width		= 8,
  parameter gp_oup_width		= 16,
  parameter gp_feedforward_coeff_length	= 3,
  parameter gp_feedforward_coeff_width	= 8,
  parameter gp_feedback_coeff_length	= 3,
  parameter gp_feedback_coeff_width	= 8,
  parameter gp_topology                 = 0  // 0:dfi, 1:dfii, 2:tfii
) (
  input  wire				i_rst_an,
  input  wire				i_ena,
  input  wire				i_clk,
  input  wire signed [gp_inp_width-1:0] i_data,
  output wire signed [gp_oup_width-1:0] o_data
);
// -------------------------------------------------------------------
generate
  if (gp_topology == 1)
    begin: IIR_DFII
      filt_iir_dfii #(
        .gp_inp_width 	             (gp_inp_width),   
	.gp_oup_width	             (gp_oup_width),
	.gp_feedforward_coeff_length (gp_feedforward_coeff_length),
	.gp_feedforward_coeff_width  (gp_feedforward_coeff_width),
	.gp_feedback_coeff_length    (gp_feedback_coeff_length),
	.gp_feedback_coeff_width     (gp_feedback_coeff_width)
      ) iir_dfii (
        .i_rst_an (i_rst_an),
	.i_ena    (i_ena),
	.i_clk    (i_clk),
	.i_data   (i_data),
	.o_data   (o_data)
      );
    end
  else if (gp_topology == 2)
    begin: IIR_TFII
      filt_iir_tfii #(
        .gp_inp_width 	             (gp_inp_width),   
	.gp_oup_width	             (gp_oup_width),
	.gp_feedforward_coeff_length (gp_feedforward_coeff_length),
	.gp_feedforward_coeff_width  (gp_feedforward_coeff_width),
	.gp_feedback_coeff_length    (gp_feedback_coeff_length),
	.gp_feedback_coeff_width     (gp_feedback_coeff_width)
      ) iir_tfii (
        .i_rst_an (i_rst_an),
	.i_ena    (i_ena),
	.i_clk    (i_clk),
	.i_data   (i_data),
	.o_data   (o_data)
      );    
    end
  else
    begin: IIR_DFI
      filt_iir_dfi #(
        .gp_inp_width 	             (gp_inp_width),   
	.gp_oup_width	             (gp_oup_width),
	.gp_feedforward_coeff_length (gp_feedforward_coeff_length),
	.gp_feedforward_coeff_width  (gp_feedforward_coeff_width),
	.gp_feedback_coeff_length    (gp_feedback_coeff_length),
	.gp_feedback_coeff_width     (gp_feedback_coeff_width)
      ) iir_dfi (
        .i_rst_an (i_rst_an),
	.i_ena    (i_ena),
	.i_clk    (i_clk),
	.i_data   (i_data),
	.o_data   (o_data)
      );    
    end
endgenerate

endmodule

// -------------------------------------------------------------------
// Direct-Form I
// -------------------------------------------------------------------
module filt_iir_dfi #(
  parameter gp_inp_width		= 8,
  parameter gp_oup_width		= 16,
  parameter gp_feedforward_coeff_length	= 3,
  parameter gp_feedforward_coeff_width	= 8,
  parameter gp_feedback_coeff_length	= 3,
  parameter gp_feedback_coeff_width	= 8
) (
  input  wire				i_rst_an,
  input  wire				i_ena,
  input  wire				i_clk,
  input  wire signed [gp_inp_width-1:0] i_data,
  output wire signed [gp_oup_width-1:0] o_data
);
// -------------------------------------------------------------------
// ff_w = coeff_w + inp_w + coeff_l
// fb_w = coeff_w + coeff_l + ff_w
localparam feedforward_dly_width  = gp_inp_width;
localparam feedforward_mul_width  = gp_inp_width + gp_feedforward_coeff_width;
localparam feedforward_addr_width = feedforward_mul_width + gp_feedforward_coeff_length;
localparam feedback_dly_width     = feedforward_addr_width;
localparam feedback_mul_width     = feedback_dly_width + gp_feedback_coeff_width;
localparam feedback_addr_width    = feedback_mul_width + gp_feedback_coeff_length;
// IIR Feed-forward (numerator) coefficients
wire signed [gp_feedforward_coeff_width-1:0] feedforward_coeff [0:gp_feedforward_coeff_length-1];
// IIR Feed-forward (denominator) coefficients
wire signed [gp_feedback_coeff_width-1   :0] feedback_coeff    [0:gp_feedback_coeff_length-1];
// Feed-forward local signals
wire        [feedforward_dly_width*(gp_feedforward_coeff_length-1)-1:0] feedforward_delayline;
wire signed [feedforward_mul_width*gp_feedforward_coeff_length-1    :0] feedforward_mul;
wire signed [feedforward_addr_width*gp_feedforward_coeff_length-1   :0] feedforward_add;
// Feed-back local signals
wire        [feedback_dly_width*(gp_feedback_coeff_length-1)-1      :0] feedback_delayline;
wire signed [feedback_mul_width*(gp_feedback_coeff_length-1)-1      :0] feedback_mul;
wire signed [feedback_addr_width*gp_feedback_coeff_length-1         :0] feedback_add;
// Feed-forward to Feed-back section connection
wire [feedforward_addr_width-1:0] ff2fb;
// -------------------------------------------------------------------
`include "iir_coeff.v"
// -------------------------------------------------------------------
assign ff2fb = feedforward_add[0*feedforward_addr_width +: feedforward_addr_width];

assign o_data = feedback_add[0*feedback_addr_width +: feedback_addr_width];

genvar i;
generate
  for (i=0; i<gp_feedforward_coeff_length-1; i=i+1)
    begin: ff_dly
      if (i==0)
        begin
      	  dff #(
      	    .gp_data_width (feedforward_dly_width)
      	  ) feedforward_dl (
      	    .i_rst_an (i_rst_an),
	    .i_ena    (i_ena),
	    .i_clk    (i_clk),
	    .i_data   (i_data),
	    .o_data   (feedforward_delayline[i*feedforward_dly_width +: feedforward_dly_width])
      	  );
        end
      else
        begin
      	  dff #(
      	    .gp_data_width (feedforward_dly_width)
      	  ) feedforward_dl (
      	    .i_rst_an (i_rst_an),
	    .i_ena    (i_ena),
	    .i_clk    (i_clk),
	    .i_data   (feedforward_delayline[(i-1)*feedforward_dly_width +: feedforward_dly_width]),
	    .o_data   (feedforward_delayline[ i*feedforward_dly_width    +: feedforward_dly_width])
      	  );	
	end
    end//ff_dl
    
  for (i=0; i<gp_feedforward_coeff_length; i=i+1)
    begin: ff_mul
      if (i==0)
        begin
	  assign feedforward_mul[i*feedforward_mul_width +: feedforward_mul_width] = $signed(i_data) * $signed(feedforward_coeff[i]);
	end
      else
        begin
	  assign feedforward_mul[i*feedforward_mul_width +: feedforward_mul_width] = $signed(feedforward_delayline[(i-1)*feedforward_dly_width +: feedforward_dly_width]) * $signed(feedforward_coeff[i]);
	end
    end//ff_mul
    
  for (i=0; i<gp_feedforward_coeff_length; i=i+1)
    begin: ff_add
      if (i==gp_feedforward_coeff_length-1)
        begin
	  assign feedforward_add[i*feedforward_addr_width +: feedforward_addr_width] = $signed(feedforward_mul[i*feedforward_mul_width +: feedforward_mul_width]);
	end
      else
        begin
	  assign feedforward_add[i*feedforward_addr_width +: feedforward_addr_width] = $signed(feedforward_mul[i*feedforward_mul_width +: feedforward_mul_width]) + $signed(feedforward_add[(i+1)*feedforward_addr_width +: feedforward_addr_width]);
	end
    end//ff_add
    
  //------------------// 
  // FEEDBACK SECTION //
  //------------------//
  for (i=0; i<gp_feedback_coeff_length; i=i+1)
    begin: fb_add
      if (i==gp_feedback_coeff_length-1)
        begin
	  assign feedback_add[i*feedback_addr_width +: feedback_addr_width] = $signed(feedback_mul[(i-1)*feedback_mul_width +: feedback_mul_width]);
	end
      else if (i==0)
        begin
	  assign feedback_add[i*feedback_addr_width +: feedback_addr_width] = $signed(feedforward_add[i*feedforward_addr_width +: feedforward_addr_width]) + $signed(feedback_add[(i+1)*feedback_addr_width +: feedback_addr_width]);
	end
      else
        begin
	  assign feedback_add[i*feedback_addr_width +: feedback_addr_width] = $signed(feedback_mul[(i-1)*feedback_mul_width +: feedback_mul_width]) + $signed(feedback_add[(i+1)*feedback_addr_width +: feedback_addr_width]);
	end
    end//fb_add
  
  for (i=0; i<gp_feedback_coeff_length-1; i=i+1)
    begin: fb_dly
      if (i==0)
        begin
      	  dff #(
      	    .gp_data_width (feedback_dly_width)
      	  ) feedback_dl (
      	    .i_rst_an (i_rst_an),
	    .i_ena    (i_ena),
	    .i_clk    (i_clk),
	    .i_data   (feedback_add[i*feedback_addr_width +: feedback_addr_width]),
	    .o_data   (feedback_delayline[i*feedback_dly_width +: feedback_dly_width])
      	  );
        end
      else
        begin
      	  dff #(
      	    .gp_data_width (feedback_dly_width)
      	  ) feedback_dl (
      	    .i_rst_an (i_rst_an),
	    .i_ena    (i_ena),
	    .i_clk    (i_clk),
	    .i_data   (feedback_delayline[(i-1)*feedback_dly_width +: feedback_dly_width]),
	    .o_data   (feedback_delayline[ i*feedback_dly_width    +: feedback_dly_width])
      	  );	
	end    
    end//fb_dly
    
  for (i=0; i<gp_feedback_coeff_length-1; i=i+1)
    begin: fb_mul
      assign feedback_mul[i*feedback_mul_width +: feedback_mul_width] = $signed(feedback_delayline[i*feedback_dly_width +: feedback_dly_width]) * $signed(feedback_coeff[i+1]);
    end//fb_mul
endgenerate
	
endmodule

// -------------------------------------------------------------------
// Direct-Form II
// -------------------------------------------------------------------
module filt_iir_dfii #(
  parameter gp_inp_width		= 8,
  parameter gp_oup_width		= 16,
  parameter gp_feedforward_coeff_length	= 3,
  parameter gp_feedforward_coeff_width	= 8,
  parameter gp_feedback_coeff_length	= gp_feedforward_coeff_length,
  parameter gp_feedback_coeff_width	= 8
) (
  input  wire				i_rst_an,
  input  wire				i_ena,
  input  wire				i_clk,
  input  wire signed [gp_inp_width-1:0] i_data,
  output wire signed [gp_oup_width-1:0] o_data
);
// -------------------------------------------------------------------
endmodule

// -------------------------------------------------------------------
// Transposed-Form II
// -------------------------------------------------------------------
module filt_iir_tfii #(
  parameter gp_inp_width		= 8,
  parameter gp_oup_width		= 16,
  parameter gp_feedforward_coeff_length	= 3,
  parameter gp_feedforward_coeff_width	= 8,
  parameter gp_feedback_coeff_length	= gp_feedforward_coeff_length,
  parameter gp_feedback_coeff_width	= 8
) (
  input  wire				i_rst_an,
  input  wire				i_ena,
  input  wire				i_clk,
  input  wire signed [gp_inp_width-1:0] i_data,
  output wire signed [gp_oup_width-1:0] o_data
);
// -------------------------------------------------------------------
// ff_w = coeff_w + inp_w + coeff_l
// fb_w = inp_w + ff_coeff_w + 2xcoeff_l + fb_coeff_w
localparam coeff_length          = gp_feedforward_coeff_length;
localparam iir_dly_width         = gp_inp_width + gp_feedforward_coeff_width + gp_feedback_coeff_width + 2*coeff_length;
localparam iir_add_width         = iir_dly_width;
localparam feedforward_mul_width = gp_inp_width + gp_feedforward_coeff_width;
localparam feedback_mul_width    = iir_add_width + gp_feedback_coeff_width;
// IIR Feed-forward (numerator) coefficients
wire signed [gp_feedforward_coeff_width-1:0] feedforward_coeff [0:coeff_length-1];
// IIR Feed-forward (denominator) coefficients
wire signed [gp_feedback_coeff_width-1   :0] feedback_coeff    [0:coeff_length-1];
// Feed-back/forward local signals
wire        [iir_dly_width*(coeff_length-1)-1:0] iir_dly;
wire signed [iir_add_width*coeff_length-1   :0] iir_add;
wire signed [feedforward_mul_width*coeff_length-1    :0] feedforward_mul;
wire signed [feedback_mul_width*coeff_length-1      :0] feedback_mul;
// -------------------------------------------------------------------
`include "iir_coeff.v"
// -------------------------------------------------------------------
assign o_data = $signed(iir_add[(0)*iir_add_width +: iir_add_width]);
genvar i;
generate
  for (i=0; i<coeff_length; i=i+1)
    begin: ff_mul
      assign feedforward_mul[i*feedforward_mul_width +: feedforward_mul_width] = $signed(i_data) * $signed(feedforward_coeff[i]);
    end

  for (i=0; i<coeff_length; i=i+1)
    begin: fb_mul
      if (i==0)
        begin
	  assign feedback_mul[i*feedback_mul_width +: feedback_mul_width] = 'd0;
	end
      else
        begin
	  assign feedback_mul[i*feedback_mul_width +: feedback_mul_width] = $signed(iir_add[0*iir_add_width +: iir_add_width]) * $signed(feedback_coeff[i]);
	end      
    end
  
  for (i=0; i<coeff_length; i=i+1)
    begin: fffb_add
      if (i==0)
        begin
	  assign iir_add[i*iir_add_width +: iir_add_width] = $signed(feedforward_mul[i*feedforward_mul_width +: feedforward_mul_width]) + $signed(iir_dly[i*iir_dly_width +: iir_dly_width]);
	end
      else if (i==coeff_length-1)
        begin
	  assign iir_add[i*iir_add_width +: iir_add_width] = $signed(feedforward_mul[i*feedforward_mul_width +: feedforward_mul_width]) + $signed(feedback_mul[i*feedback_mul_width +: feedback_mul_width]);
	end
      else
        begin
	  assign iir_add[i*iir_add_width +: iir_add_width] = $signed(feedforward_mul[i*feedforward_mul_width +: feedforward_mul_width]) + $signed(feedback_mul[i*feedback_mul_width +: feedback_mul_width]) + $signed(iir_dly[i*iir_dly_width +: iir_dly_width]);
	end
	
    end
    
  for (i=0; i<coeff_length-1; i=i+1)
    begin        
      dff #(
        .gp_data_width (iir_dly_width)
      ) feedforward_dl (
        .i_rst_an (i_rst_an),
        .i_ena    (i_ena),
        .i_clk    (i_clk),
        .i_data   (iir_add[(i+1)*iir_dly_width +: iir_dly_width]),
        .o_data   (iir_dly[i*iir_dly_width +: iir_dly_width])
      );    
    end
endgenerate  

endmodule
