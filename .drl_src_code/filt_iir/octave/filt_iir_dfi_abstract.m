close all
clear
clc

b = [.10 20 30];
a = [1 50 20];

DEBUG = 'true';

NoS = 2^2;
x = 1:NoS;
delay_line_ff = zeros(1,length(b));
delay_line_fb = zeros(1,length(a));

if DEBUG
  fid = fopen('debug_iir_dfi.dat','w');
end
%% -----------------------------------------------------------------------------
%% DIRECT-FORM I
%% -----------------------------------------------------------------------------
for i = 1 : NoS
   % FEEDFORWARD SECTION
  delay_line_ff = [x(i) delay_line_ff(1:end-1)];
  mul_ff        = b .* delay_line_ff;
  ff2fb         = sum(mul_ff);
  % FEEDBACK SECTION  
  out_fb        = ff2fb - sum(a(2:end) .* delay_line_fb(1:end-1));
  delay_line_fb = [out_fb delay_line_fb(1:end-1)];
  mul_fb        = a .* delay_line_fb;
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

y = filter(b, a, x);
[y' iir_dfi']
%% -----------------------------------------------------------------------------
%% DIRECT-FORM II
%% -----------------------------------------------------------------------------
if DEBUG
  fid = fopen('debug_iir_dfii.dat','w');
end

delay_line = zeros(1,length(b));

for i = 1 : NoS
  % FEEDBACK SECTION
  fb2ff = x(i) - sum(a(2:end) .* delay_line(1:end-1));
  % COMMON DELAY LINE
  delay_line = [fb2ff delay_line(1:end-1)];
  % FEEDFORWARD SECTION
  mul_ff = b.* delay_line;
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
iir_dfii
%% -----------------------------------------------------------------------------
%% TRANSPOSED-FORM II
%% -----------------------------------------------------------------------------
if DEBUG
  fid = fopen('debug_iir_tfii.dat','w');
end
a = [a(1) -a(2:end)];
delay_line = zeros(1,length(b));

for i = 1 : length(x)
  % FEEDFORWARD SECTION
  mul_ff = b .* x(i);
  % FEEDFORWARD-TO-FEEDBACK
  ff2fb = mul_ff(1) + delay_line(2);
  % FEEDBACK SECTION
  mul_fb = a .* ff2fb;
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
iir_tfii