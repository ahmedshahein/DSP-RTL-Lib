package cordic_pkg;
  
  function void gen_atan_lut (int nr_iter, int angle_resolution, string path="./");
    int    atan_int;
    real   atan_real;
    int    fid;
    string filename;
    
    filename = {path,"atan_lut.v"};
    
    fid = $fopen(filename, "w");
    for (int i = 0; i < nr_iter; i++) 
      begin
        atan_real = $atan(2.0**-$itor(i));      
        atan_int = $floor( (2**(angle_resolution-2)) * atan_real + 0.5 );
        $display("%f\t%d", atan_real, atan_int);
        $fdisplay(fid, "assign atan_lut[%0d] = %0d'd%0d;", i, angle_resolution, atan_int);
      end    
   $fclose(fid); 
  endfunction : gen_atan_lut
  
endpackage : cordic_pkg

module cordic_pkg_tb;
  import cordic_pkg::*;
  
  initial gen_atan_lut(16, 16, "./rtl/");
endmodule
