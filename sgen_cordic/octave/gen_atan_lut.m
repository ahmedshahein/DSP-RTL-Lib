clear
clc

n = 16;

for i = 1 : 16,
  atan_lut(i) = round(atand(2^-(i-1))*2^n);
  atan_lut2(i) = floor(atan(2^-(i-1))*2^n/(2*pi)+0.5);
endfor

[atan_lut' atan_lut2']
angle_resolution = 1/2^n
