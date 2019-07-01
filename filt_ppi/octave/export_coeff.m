
FID = fopen("filt_coeff.v", "w");

for i = 1 : ceil(length(b)/2),
  if b(i) < 0,
    fprintf(FID, "assign p_coeff[%d] = -8'sd%d;\n", i-1, abs(b(i)));
  else  
  fprintf(FID, "assign p_coeff[%d] =  8'sd%d;\n", i-1, b(i));
  end
end

fclose(FID);