%NCO bit true model
clear all; close all;

fo = 150;
fs = 10e3;
fcw = fo/fs;
Q = 8;
%example NCO parameters
n = 333;%20000;                     %number of test samples
A = 2^Q - 1;                  %max amplitude, amplitude resolution 16 bit signed
M = 2^16;                      %NCO accumulator phase resolution
inc = floor(M*fcw);           %NCO accumulator phase increment 
k = 2^8;                      %lut phase resolution (lut size), may equal M

%single equation for NCO bit true model
y1 = round(A*sin(2*pi*round(k*mod((0:n-1)*inc/M,M))/k));      

%%%%%%%%%%%%%%%%%%%%%%%%% equivalent code %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
lsb = log2(M) - log2(k);                 %LSBs discarded when addressing
lut = round(A*sin(2*pi*(0:k-1)/k));      %lut, one cycle sine data

ptr = 0; 
addr = 0;
for i = 1:n 
    y2(i) = lut(addr+1);          %add 1 for matlab LUT
    ptr = mod(ptr + inc, M);      %phase accumulator(ramp)
    addr = floor(ptr/2^lsb);      %discard LSBs %%round
    addr(addr >= k) = addr - k;   %check address overflow
end

%compare
plot(y1);hold;
plot(y2,'r--')
plot(y1 - y2,'g--')