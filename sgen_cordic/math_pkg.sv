package math_pkg;

  //import DPI-C task      C Name = SV function name

  import "DPI-C" pure function real cos (input real rTheta);

  import "DPI-C" pure function real sin (input real rTheta);
  
  import "DPI-C" pure function real atan (input real rTheta);

  import "DPI-C" pure function real log (input real rVal);

  import "DPI-C" pure function real log10 (input real rVal);

endpackage : math_pkg
