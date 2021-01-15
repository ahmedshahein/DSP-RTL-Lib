function gen_coeffs(b, a, qb, qa)
  
FID = fopen("iir_coeff.v", "w");

for i = 1 : length(b),
  if b(i) < 0,
    fprintf(FID, "assign feedforward_coeff[%d] = -%d'sd%d;\n", i-1, qb, abs(b(i)));
  else  
    fprintf(FID, "assign feedforward_coeff[%d] =  %d'sd%d;\n", i-1, qb, b(i));
  end
end

for i = 1 : length(a),
  if a(i) < 0,
    fprintf(FID, "assign feedback_coeff[%d] = -%d'sd%d;\n", i-1, qa, abs(a(i)));
  else  
    fprintf(FID, "assign feedback_coeff[%d] =  %d'sd%d;\n", i-1, qa, a(i));
  end
end

fclose(FID);