function y2 = nco(param)
% The NCO model is developed by Kadhiem Ayob and it is posted at dsprelated!
% https://www.dsprelated.com/showcode/228.php
% Design Parameters
fo    = param.fo;
fs    = param.fs;
n     = param.nr_of_samples;            %number of test samples
A     = param.ampl*2^(param.gp_rom_width-1) ;       %max amplitude, amplitude resolution
M     = 2^param.gp_phase_accu_width;    %NCO accumulator phase resolution
fcw   = floor(M*fo/fs);                 %NCO accumulator phase fcwrement 
k     = 2^param.gp_rom_depth;           %lut phase resolution (lut size), may equal M

% Single equation for NCO bit true model
lsb   = log2(M) - log2(k);              %LSBs discarded when addressing
lut   = round(A*sin(2*pi*(0:k-1)/k));   %lut, one cycle sine data     %lut, one cycle sine data

r_min = -10000;
r_max =  10000;
r = r_min + (r_max - r_min)*rand(1,n);

ptr   = 0; 
addr  = 0;
for i = 1:n 
    y2(i)           = lut(addr+1);          %add 1 for matlab LUT
    ptr             = mod(ptr + fcw, M)+r(i);    %phase accumulator(ramp)
    addr            = floor(ptr/2^lsb);     %discard LSBs %%round
    addr(addr >= k) = addr - k;             %check address overflow
end
%% EOF