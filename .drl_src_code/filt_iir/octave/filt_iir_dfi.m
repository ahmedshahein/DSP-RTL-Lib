function [iir_dfi_oup y_ref] = filt_iir_dfi (feedforward_coeff,feedback_coeff,i_data,DEBUG)
% ------------------------------------------------------------------------------
% This function is developed to implement IIR digital filter in Direct-Form I 
% (DFI) topology. The function takes the numerator (feedforward) and denominator
% (feedback) coefficients of an IIR transfer function. In addition to input bit
% stream.
% Inputs:
% feedforward_coeff: Transfer function numerator (b coefficients)
% feedback_coeff: Transfer function denominator (a coefficients)
% i_data: Input bit stream
% DEBUG: If enabled save internal filter values into 'iir_dfi_debug.dat'
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
  feedforward_delayline = zeros(1, feedforward_order+1);
  feedforward_mul       = zeros(1,feedforward_order+1);
  feedforward_add       = zeros(1,feedforward_order+1);

  feedback_order        = length(feedback_coeff) - 1;
  feedback_coeff_ref    = [1 -feedback_coeff(2:end)];
  feedback_delayline    = zeros(1, feedback_order+1);
  feedback_mul          = zeros(1,feedback_order+1);
  feedback_add          = zeros(1,feedback_order+1);

  if DEBUG
    fid = fopen("iir_dfi_debug.dat","w");
  endif  

  for i = 1 : length(i_data),
    %% Feedforward Section
    feedforward_delayline = [i_data(i) feedforward_delayline(1:end-1)];
    for j = 1 : feedforward_order+1,
      feedforward_mul(j) = feedforward_delayline(j) * feedforward_coeff(j);
    endfor

    for k = feedforward_order+1:-1:1,
      if k == feedforward_order+1,
        feedforward_add(k) = feedforward_mul(k);
      else
        feedforward_add(k) = feedforward_mul(k) + feedforward_add(k+1);
      endif
    endfor
    
    ff2fb = feedforward_add(1);
    %% Feedback Section
    feedback_delayline = [feedback_add(1) feedback_delayline(1:end-1)];

    for j = 2 : feedback_order+1,
      feedback_mul(j) = feedback_delayline(j-1) * feedback_coeff(j);
    endfor

    for k = feedback_order+1:-1:2,
      if k == feedback_order+1,
        feedback_add(k) = feedback_mul(k);
      else
        feedback_add(k) = feedback_mul(k) + feedback_add(k+1);
      endif
    endfor

    feedback_add(1) = ff2fb + feedback_add(2);
    
    iir_dfi_oup(i) = feedback_add(1);
    
    if DEBUG,
      fprintf(fid, "%d %s\n", i, "DLY_FF");
      fprintf(fid, "%f\n",feedforward_delayline);
      fprintf(fid, "%d %s\n", i, "MUL_FF");
      fprintf(fid, "%f\n",feedforward_mul);
      fprintf(fid, "%d %s\n", i, "ADD_FF");
      fprintf(fid, "%f\n",feedforward_add); 
      fprintf(fid, "\n");
      
      fprintf(fid, "%d %s\n", i, "DLY_FB");
      fprintf(fid, "%f\n",feedback_delayline);
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
