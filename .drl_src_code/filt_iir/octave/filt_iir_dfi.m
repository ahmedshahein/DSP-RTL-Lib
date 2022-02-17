function [iir_dfi y_ref] = filt_iir_dfi (feedforward_coeff,feedback_coeff,i_data,DEBUG)
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

%% -----------------------------------------------------------------------------
%% DIRECT-FORM I
%% -----------------------------------------------------------------------------
  delay_line_ff = zeros(1,length(feedforward_coeff));
  delay_line_fb = zeros(1,length(feedback_coeff));

  if DEBUG
    fid = fopen('debug_iir_dfi.dat','w');
  end
  for i = 1 : length(i_data)
     % FEEDFORWARD SECTION
    delay_line_ff = [i_data(i) delay_line_ff(1:end-1)];
    mul_ff        = feedforward_coeff .* delay_line_ff;
    ff2fb         = sum(mul_ff);
    % FEEDBACK SECTION  
    out_fb        = ff2fb - sum(feedback_coeff(2:end) .* delay_line_fb(1:end-1));
    delay_line_fb = [out_fb delay_line_fb(1:end-1)];
    mul_fb        = feedback_coeff .* delay_line_fb;
    % DFI OUTPUT
    iir_dfi(i)    = out_fb;  
    % DEBUG
    if DEBUG
      fprintf(fid,'######### CLOCK %d\n', i);
      fmt = ['MUL_FF =' repmat(' %0f ',1,numel(mul_ff)) '\n'];
      fprintf(fid, fmt,mul_ff);
      fmt = ['DLY_FF =' repmat(' %0f ',1,numel(delay_line_ff)) '\n'];
      fprintf(fid, fmt, delay_line_ff);
      fmt = ['MUL_FB =' repmat(' %0f ',1,numel(mul_fb)) '\n'];
      fprintf(fid, fmt, mul_fb);
      fmt = ['DLY_FB =' repmat(' %0f ',1,numel(delay_line_fb)) '\n'];
      fprintf(fid, fmt, delay_line_fb);    
    end      
  end
  fclose(fid);

  y_ref = filter(feedforward_coeff,feedback_coeff,i_data);

endfunction
