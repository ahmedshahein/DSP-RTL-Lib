
module fir_mac (
  input                i_rst_an,
  input                i_clk,
  input                i_ena,
  input  signed [16:0] i_data,
  output signed [26:0] o_data
);
// ----------------------------------------------------------------
localparam N = 5;
localparam M = (N-1)/2;
localparam signed [5:0] h [0:M] = '{10, 14, 17};

/*localparam N = 11;
localparam M = (N-1)/2;
localparam signed [5:0] h [0:10] = '{-3, -1, 3, 9, 15, 17, 15, 9, 3, -1, -3};*/

localparam B = $clog2(N);

reg [B-1:0] r_sel_coeff;

wire signed [ 5:0] w_coeff;
wire signed [16:0] w_data;
wire signed [22:0] w_mul_oup;
wire signed [26:0] w_add_oup;
wire               w_load_i_data;

reg  signed [26:0] r_add_oup;
reg  signed [16:0] r_delay_line [N-1:0];
reg  signed [26:0] r_data;

integer idx;
// ----------------------------------------------------------------
always @(posedge i_clk or negedge i_rst_an)
  begin : CTRL
    if (!i_rst_an)
      r_sel_coeff <= {B{1'b1}};
    else if (i_ena)
      begin
        if (r_sel_coeff < M)
	  r_sel_coeff <= r_sel_coeff + 1'b1;
	else if (r_sel_coeff == N)
	  r_sel_coeff <= 'd0;
	else
	  r_sel_coeff <= N;
      end
  end

assign w_load_i_data = (r_sel_coeff == N) ? 1'b1 : 1'b0;
  
always @(posedge i_clk or negedge i_rst_an)
  begin : DELAY_LINE
    if (!i_rst_an)
      begin
        for (idx=0; idx<N; idx=idx+1)
	  r_delay_line[idx] <= 'd0;
      end
    else if (i_ena)
      begin
        if (w_load_i_data) begin
        r_delay_line[N-1] <= i_data;
        for (idx=N-2;idx>=0;idx=idx-1)
          r_delay_line[idx] <= r_delay_line[idx+1];
	end  
      end
  end

assign w_coeff = (r_sel_coeff < N) ? h[r_sel_coeff] : 'd0;

assign w_data  = (r_sel_coeff < M) ? r_delay_line[N-1-r_sel_coeff] + r_delay_line[r_sel_coeff] 
                                   : (r_sel_coeff == M) ? r_delay_line[r_sel_coeff] 
				                        : 'd0;

// MULT
assign w_mul_oup = w_data * w_coeff;				   
// ACCU
assign w_add_oup = w_mul_oup + r_add_oup;

always @(posedge i_clk or negedge i_rst_an)
  begin : ADDER
    if (!i_rst_an)
      r_add_oup <= 'd0;
    else if (i_ena)
      if (w_load_i_data)
        r_add_oup <= 'd0;
      else
        r_add_oup <= w_add_oup;
  end
// OUP PIPE-LINE
always @(posedge i_clk or negedge i_rst_an)
  begin
    if (!i_rst_an)
      r_data <= 'd0;
    else if (i_ena)
      begin
        if (w_load_i_data)
	  r_data <= r_add_oup;
      end
  end 
  
assign o_data = r_data;

endmodule


module fir_mac_tb;

reg i_rst_an;
reg i_clk;
reg i_ena;
reg signed [16:0]  i_data;

initial
  begin
         i_rst_an = 1'b1;
    #1   i_rst_an = 1'b0;
    #105 i_rst_an = 1'b1;
  end

always
  begin
    i_clk = 1'b0;
    #50;
    i_clk = 1'b1;
    #50;
  end

initial
  begin
    i_ena = 1'b0;
    #400 i_ena = 1'b1;
  end

initial
  begin
    i_data = 'd1; #850;  //$random() % 2**16;
    i_data = 'd2; #400;
    i_data = 'd3; #400;
    i_data = 'd2; #400;
    i_data = 'd1; #400;
    i_data = 'd1; #400;
    i_data = 'd1; #400;
    i_data = 'd1; #400;
    i_data = 'd1; #400;
    i_data = 'd1; #400;
    i_data = 'd1; #400;
    i_data = 'd1; #400;
  end
      
fir_mac dut (
  .i_rst_an (i_rst_an),
  .i_clk    (i_clk),
  .i_ena    (i_ena),
  .i_data   (i_data),
  .o_data   ()
);

endmodule
