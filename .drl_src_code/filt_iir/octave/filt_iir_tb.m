close all
clear
clc

i_data = 0:9;
DEBUG = 'false';

feedforward_coeff = [10 20 30];
feedback_coeff    = [1 -20 -30];

topology = '';

%[n,Wn] = buttord(Wp,Ws,Rp,Rs)
##[n,Wn] = buttord([1000 2000]/5000,[500 2500]/5000,1,60)
##[b,a] = butter(1,Wn);
##feedforward_coeff = b;
##feedback_coeff = a;

[iir_dfi_oup y_ref] = filt_iir (feedforward_coeff,feedback_coeff,i_data,DEBUG,'dfi');
[iir_dfii_oup y_ref] = filt_iir (feedforward_coeff,feedback_coeff,i_data,DEBUG,'dfii');
[iir_tfii_oup y_ref] = filt_iir (feedforward_coeff,feedback_coeff,i_data,DEBUG,'tfii');


[iir_dfi_oup' iir_dfii_oup' iir_tfii_oup' y_ref']