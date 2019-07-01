function gen_coeffs(b, q, symm)
  
FID = fopen("filt_coeff.v", "w");

if (symm==1)
  filt_len = ceil(length(b)/2);
else
  filt_len = length(b);
endif

for i = 1 : filt_len,
  if b(i) < 0,
    fprintf(FID, "assign c_coeff[%d] = -%d'sd%d;\n", i-1, q, abs(b(i)));
  else  
    fprintf(FID, "assign c_coeff[%d] =  %d'sd%d;\n", i-1, q, b(i));
  end
end

fclose(FID);