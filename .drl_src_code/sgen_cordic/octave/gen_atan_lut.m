function gen_atan_lut(n_iter, bitwidth)
  % This function generates the LUT for the ATAN power-of-two values for the 
  % CORDIC algorithm.
  % The bit-width shall consider signed fixed-point values despite that all the
  % values are positive.
  atan_lut = atan(2.^-[0:n_iter-1]);
  atan_lut_q = uquant(atan_lut, bitwidth, "s");
  atan_lut_s = floor(atan_lut_q.*2^(bitwidth-2));
  fid = fopen("atan_lut.v", "w");
  for i = 1 : n_iter,
    fprintf(fid, "assign atan_lut[%d] =  %d'sd%d;\n", i-1, bitwidth, atan_lut_s(i));
  end

  fclose(fid);