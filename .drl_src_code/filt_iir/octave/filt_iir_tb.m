close all
clear
clc

i_data = 0:9;
DEBUG = 'false';

##feedforward_coeff = [11 25 37];
##feedback_coeff    = [3 -2 -3];

feedforward_coeff = [0.070312	0.13281	0.070312];
feedback_coeff    = [0.99219	-1	0.41406];

if feedback_coeff(1) ~= 1
  feedforward_coeff = feedforward_coeff./feedback_coeff(1);
  feedback_coeff    = feedback_coeff./feedback_coeff(1);
end

topology = '';

[iir_dfi_oup y_ref_dfi]   = filt_iir (feedforward_coeff,feedback_coeff,i_data,DEBUG,'dfi');
[iir_dfii_oup y_ref_dfii] = filt_iir (feedforward_coeff,feedback_coeff,i_data,DEBUG,'dfii');
[iir_tfii_oup y_ref_tfii] = filt_iir (feedforward_coeff,feedback_coeff,i_data,DEBUG,'tfii');

y_ref_dfi == y_ref_dfii == y_ref_tfii
[iir_dfi_oup' iir_dfii_oup' iir_tfii_oup' y_ref_dfi']
