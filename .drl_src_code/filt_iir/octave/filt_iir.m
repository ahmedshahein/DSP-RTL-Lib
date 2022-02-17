function [iir_oup y_ref] = filt_iir (feedforward_coeff,feedback_coeff,i_data,DEBUG,topology)
% ------------------------------------------------------------------------------
% This function is just a wrapper as a top-level function to design digital
% IIR filter in various topologies such as 
% Direct-Form I 'dfi'
% Direct-Form II 'dfii'
% Transposed-Form II 'tfii' 
% Inputs:
% feedforward_coeff: Transfer function numerator (b coefficients)
% feedback_coeff: Transfer function denominator (a coefficients)
% i_data: Input bit stream
% DEBUG: If enabled save internal filter values into 'iir_<TOPOLOGY>_debug.dat'
% Outputs:
% iir_dfi_oup: Expected output based on given inputs
% y_ref: Reference output using 'filter(feedforward_coeff,feedback_coeff_ref,i_data);'
% Transfer Function:
% H(z) = b(0) + b(1)z^-1 + b(2)z^-2 / 1 - a(1)z^-1 - a(2)z^-2
% ------------------------------------------------------------------------------
% Ahmed Shahein (C) 2021
% ahmed.shahein@vlsi-design.org
% ------------------------------------------------------------------------------ 
  switch (topology)
    case {'dfii'}
      [iir_oup y_ref] = filt_iir_dfii (feedforward_coeff,feedback_coeff,i_data,DEBUG);
    case {'tfii'}
      [iir_oup y_ref] = filt_iir_tfii (feedforward_coeff,feedback_coeff,i_data,DEBUG);
    otherwise
      [iir_oup y_ref] = filt_iir_dfi (feedforward_coeff,feedback_coeff,i_data,DEBUG);
  endswitch
endfunction
