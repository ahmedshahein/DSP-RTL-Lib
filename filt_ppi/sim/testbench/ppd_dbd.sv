`define P_ROW		`P_DECIMATION
`define P_COL		(`DIV(`P_COEFF_L,`P_DECIMATION))
`define P_MUL_OUP_W	(`P_INP_DATA_W+`P_COEFF_W)
`define P_ADD_OUP_W	(`P_MUL_OUP_W+`P_DECIMATION)
  
  int ppd_mul_matrix[][];
  int ppd_add_matrix[][];
  int z;
  reg [`P_MUL_OUP_W*`P_ROW*`P_COL-1:0] r_mul;
  reg [`P_ADD_OUP_W*`P_ROW*`P_COL-1:0] r_add;
  
  initial
    begin
      $display("### INFO: PPD coefficient length \t\t\t= %2d", `P_COEFF_L);
      $display("### INFO: PPD coefficient matrix [row][col] \t= [%2d][%2d]", `P_ROW, `P_COL);
      $display("### INFO: PPD multiplier output width \t\t= %2d", `P_MUL_OUP_W);
      $display("### INFO: PPD adder output width \t\t\t= %2d", `P_ADD_OUP_W);
      
      assign r_mul = dut.ppd_mul_add.w_mul;
      assign r_add = dut.ppd_mul_add.w_add_tree;
      
      ppd_mul_matrix = new[`P_ROW];
      foreach(ppd_mul_matrix[i]) ppd_mul_matrix[i] = new[`P_COL];
      
      ppd_add_matrix = new[`P_ROW-1];
      foreach(ppd_add_matrix[i]) ppd_add_matrix[i] = new[`P_COL];      
    end
  
  always @(negedge s_clk)
    begin
      z=0;
      for (int i = 0; i < `P_COL; i++) begin
        for (int j = 0; j < `P_ROW; j++) begin
          ppd_mul_matrix[j][i] = $signed(r_mul[z*`P_MUL_OUP_W +: `P_MUL_OUP_W]);
          z++;           
          $write(" MUL:: ",ppd_mul_matrix[j][i]);
        end
	$display("\n");
      end 
    end
    
  always @(negedge s_clk)
    begin
      z=0;
      for (int i = 0; i < `P_COL; i++) begin
        for (int j = 0; j < `P_ROW-1; j++) begin
          ppd_add_matrix[j][i] = $signed(r_add[z*`P_ADD_OUP_W +: `P_ADD_OUP_W]);
          z++;           
          $write(" ADD:: ", ppd_add_matrix[j][i]);
        end
	$display("\n");
      end 
    end
