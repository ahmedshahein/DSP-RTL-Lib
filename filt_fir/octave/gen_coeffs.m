function gen_coeffs(b, q)
  
FID = fopen("filt_coeff.v", "w");

for i = 1 : ceil(length(b)/2),
  if b(i) < 0,
    fprintf(FID, "assign c_coeff[%d] = -%d'sd%d;\n", i-1, q, abs(b(i)));
  else  
    fprintf(FID, "assign c_coeff[%d] =  %d'sd%d;\n", i-1, q, b(i));
  end
end

fclose(FID);