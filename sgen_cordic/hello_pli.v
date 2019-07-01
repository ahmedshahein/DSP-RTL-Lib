
module hello_pli ();
// User-defined function
import "DPI-C" function void hello();
import "DPI-C" function real sin(real in); // sine function in C math library

initial begin
  $hello;
  #10 $finish;
end
  	  
endmodule
