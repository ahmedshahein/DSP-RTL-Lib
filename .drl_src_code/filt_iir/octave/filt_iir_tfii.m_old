function [iir_tfii_oup y_ref] = filt_iir_tfii (feedforward_coeff,feedback_coeff,i_data,DEBUG)
% ------------------------------------------------------------------------------
% This function is developed to implement IIR digital filter in Transposed-Form II 
% (TFII) topology. The function takes the numerator (feedforward) and denominator
% (feedback) coefficients of an IIR transfer function. In addition to input bit
% stream.
% Inputs:
% feedforward_coeff: Transfer function numerator (b coefficients)
% feedback_coeff: Transfer function denominator (a coefficients)
% i_data: Input bit stream
% DEBUG: If enabled save internal filter values into 'iir_tfii_debug.dat'
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
  iir_add               = zeros(1,feedforward_order+1);
  iir_delayline         = zeros(1, feedforward_order);
  feedback_order        = length(feedback_coeff) - 1;
  feedback_coeff_ref    = [1 -feedback_coeff(2:end)];
  feedback_mul          = zeros(1,feedback_order+1);

  if DEBUG
      fid = fopen("iir_tfii_debug.dat","w");
  endif
    
  for i = 1 : length(i_data),
    %% Feedforward Section
    for j = 1 : feedforward_order+1,
      feedforward_mul(j) = i_data(i) * feedforward_coeff(j);
    endfor
    iir_add(1) = feedforward_mul(1) + iir_delayline(1);
    %% Feedback Section
    for j = 2 : feedback_order+1,
      feedback_mul(j) = iir_add(1) * feedback_coeff(j);
    endfor  

    
    for k = feedforward_order+1:-1:2,
      if k == feedforward_order+1,
        iir_add(k) = feedforward_mul(k) + feedback_mul(k);
      else
        iir_add(k) = feedforward_mul(k) + feedback_mul(k) + iir_delayline(k);
      endif
    endfor

      for l = 1 : feedforward_order,
      iir_delayline(l) = iir_add(l+1);
    endfor
      
    iir_tfii_oup(i) = iir_add(1);
    
    if DEBUG,
      fprintf(fid, "%d %s\n", i, "DLY_FF");
      fprintf(fid, "%f\n",iir_delayline);
      fprintf(fid, "%d %s\n", i, "MUL_FF");
      fprintf(fid, "%f\n",feedforward_mul);
      fprintf(fid, "%d %s\n", i, "ADD_FF");
      fprintf(fid, "%f\n",iir_add); 
      fprintf(fid, "\n");
      
      fprintf(fid, "%d %s\n", i, "DLY_FB");
      fprintf(fid, "%f\n",iir_delayline);
      fprintf(fid, "%d %s\n", i, "MUL_FB");
      fprintf(fid, "%f\n",feedback_mul);
      fprintf(fid, "%d %s\n", i, "ADD_FB");
      fprintf(fid, "%f\n",iir_add); 
      fprintf(fid, "\n");    
    endif
    
  endfor

  if DEBUG
      fclose(fid);
  endif

  y_ref = filter(feedforward_coeff,feedback_coeff_ref,i_data);
  
endfunction
