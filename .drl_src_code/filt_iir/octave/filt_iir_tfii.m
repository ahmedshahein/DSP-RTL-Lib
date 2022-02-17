function [iir_tfii y_ref] = filt_iir_tfii (feedforward_coeff,feedback_coeff,i_data,DEBUG)
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

%% -----------------------------------------------------------------------------
%% TRANSPOSED-FORM II
%% -----------------------------------------------------------------------------
  if DEBUG
    fid = fopen('debug_iir_tfii.dat','w');
  end
  feedback_coeff = [feedback_coeff(1) -feedback_coeff(2:end)];
  delay_line = zeros(1,length(feedforward_coeff));

  for i = 1 : length(i_data)
    % FEEDFORWARD SECTION
    mul_ff = feedforward_coeff .* i_data(i);
    % FEEDFORWARD-TO-FEEDBACK
    ff2fb = mul_ff(1) + delay_line(2);
    % FEEDBACK SECTION
    mul_fb = feedback_coeff .* ff2fb;
    % COMMON DELAY LINE
    for j = 1 : length(delay_line)
      if j == length(delay_line)
        delay_line(j) = mul_ff(j) + mul_fb(j); 
      elseif j == 1
        delay_line(j) = mul_ff(j)             + delay_line(j+1);
      else
        delay_line(j) = mul_ff(j) + mul_fb(j) + delay_line(j+1); 
      end
    end
    % TFII OUTPUT
    iir_tfii(i) = ff2fb;
    % DEBUG
    if DEBUG
      fprintf(fid,'######### CLOCK %d\n', i);
      fmt = ['MUL_FF =' repmat(' %0f ',1,numel(mul_ff)) '\n'];
      fprintf(fid, fmt,mul_ff);
      fmt = ['MUL_FB =' repmat(' %0f ',1,numel(mul_fb)) '\n'];
      fprintf(fid, fmt, mul_fb);
      fmt = ['DLY =' repmat(' %0f ',1,numel(delay_line)) '\n'];
      fprintf(fid, fmt, delay_line);    
    end    
    
  endfor
  fclose(fid);

  y_ref = filter(feedforward_coeff,feedback_coeff,i_data);
  
endfunction
