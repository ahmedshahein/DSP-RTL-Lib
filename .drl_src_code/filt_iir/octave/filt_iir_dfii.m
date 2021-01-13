function [iir_dfii_oup y_ref] = filt_iir_dfii (feedforward_coeff,feedback_coeff,i_data,DEBUG)
% ------------------------------------------------------------------------------
% This function is developed to implement IIR digital filter in Direct-Form II 
% (DFII) topology. The function takes the numerator (feedforward) and denominator
% (feedback) coefficients of an IIR transfer function. In addition to input bit
% stream.
% Inputs:
% feedforward_coeff: Transfer function numerator (b coefficients)
% feedback_coeff: Transfer function denominator (a coefficients)
% i_data: Input bit stream
% DEBUG: If enabled save internal filter values into 'iir_dfii_debug.dat'
% Outputs:
% iir_dfi_oup: Expected output based on given inputs
% y_ref: Reference output using 'filter(feedforward_coeff,feedback_coeff_ref,i_data);'
% Transfer Function:
% H(z) = b(0) + b(1)z^-1 + b(2)z^-2 / 1 - a(1)z^-1 - a(2)z^-2
% ------------------------------------------------------------------------------
% Ahmed Shahein (C) 2021
% ahmed.shahein@vlsi-design.org
% ------------------------------------------------------------------------------
  feedforward_order     = length(feedforward_coeff) - 1;
  feedforward_mul       = zeros(1,feedforward_order+1);
  feedforward_add       = zeros(1,feedforward_order+1);
  iir_delayline         = zeros(1, feedforward_order);
  feedback_order        = length(feedback_coeff) - 1;
  feedback_coeff_ref    = [1 -feedback_coeff(2:end)];
  feedback_mul          = zeros(1,feedback_order+1);
  feedback_add          = zeros(1,feedback_order+1);
  
  if DEBUG
      fid = fopen("iir_dfii_debug.dat","w");
  endif
    
  for j = 1 : length(i_data),
    
    iir_delayline = [feedback_add(1) iir_delayline(1:end-1)];

    for i = 2 : feedback_order+1,
      if (i == 1),
        feedback_mul(i) = feedback_add(i);
      else
        feedback_mul(i) = iir_delayline(i-1) * feedback_coeff(i);
      endif    
    endfor 

   for i = feedback_order+1:-1:1,
      if i == 1,
        feedback_add(i) = feedback_add(i+1) + i_data(j);
      elseif (i < feedforward_order+1),
        feedback_add(i) = feedback_mul(i) + feedback_add(i+1);
      else
        feedback_add(i) = feedback_mul(i);
      endif    
    endfor   

    for i = 1 : feedforward_order+1,
      if (i == 1),
        feedforward_mul(i) = feedback_add(i) * feedforward_coeff(i);
      else
        feedforward_mul(i) = iir_delayline(i-1) * feedforward_coeff(i);
      endif    
    endfor

    for i = feedforward_order+1:-1:1,
      if (i < feedforward_order+1),
        feedforward_add(i) = feedforward_mul(i) + feedforward_add(i+1);
      else
        feedforward_add(i) = feedforward_mul(i);
      endif    
    endfor 
    
    iir_dfii_oup(j) = feedforward_add(1);
    
    if DEBUG,
      fprintf(fid, "%d %s\n", i, "DLY_FF");
      fprintf(fid, "%f\n",iir_delayline);
      fprintf(fid, "%d %s\n", i, "MUL_FF");
      fprintf(fid, "%f\n",feedforward_mul);
      fprintf(fid, "%d %s\n", i, "ADD_FF");
      fprintf(fid, "%f\n",feedforward_add); 
      fprintf(fid, "\n");
      
      fprintf(fid, "%d %s\n", i, "DLY_FB");
      fprintf(fid, "%f\n",iir_delayline);
      fprintf(fid, "%d %s\n", i, "MUL_FB");
      fprintf(fid, "%f\n",feedback_mul);
      fprintf(fid, "%d %s\n", i, "ADD_FB");
      fprintf(fid, "%f\n",feedback_add); 
      fprintf(fid, "\n");    
    endif
    
  endfor

  if DEBUG
      fclose(fid);
  endif

  y_ref = filter(feedforward_coeff,feedback_coeff_ref,i_data);

endfunction
