function [iir_dfii y_ref] = filt_iir_dfii (feedforward_coeff,feedback_coeff,i_data,DEBUG)
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

%% -----------------------------------------------------------------------------
%% DIRECT-FORM II
%% -----------------------------------------------------------------------------
  if DEBUG
    fid = fopen('debug_iir_dfii.dat','w');
  end

  delay_line = zeros(1,length(feedforward_coeff));

  for i = 1 : length(i_data)
    % FEEDBACK SECTION
    fb2ff = i_data(i) - sum(feedback_coeff(2:end) .* delay_line(1:end-1));
    % COMMON DELAY LINE
    delay_line = [fb2ff delay_line(1:end-1)];
    % FEEDFORWARD SECTION
    mul_ff = feedforward_coeff.* delay_line;
    % DFII OUTPUT
    iir_dfii(i) = sum(mul_ff);
    % DEBUG
    if DEBUG
      fprintf(fid,'######### CLOCK %d\n', i);
      fmt = ['MUL_FF =' repmat(' %0f ',1,numel(mul_ff)) '\n'];
      fprintf(fid, fmt,mul_ff);
      fmt = ['MUL_FB =' repmat(' %0f ',1,numel(fb2ff)) '\n'];
      fprintf(fid, fmt, fb2ff);
      fmt = ['DLY =' repmat(' %0f ',1,numel(delay_line)) '\n'];
      fprintf(fid, fmt, delay_line);    
    end  
  endfor
  fclose(fid);

  y_ref = filter(feedforward_coeff,feedback_coeff,i_data);

endfunction
