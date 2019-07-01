clear
clc

n = 3;
phi_num = 0:2^n-1;
phi_rad = 0:2*pi/2^n:2*pi-2*pi/2^n;

[phi_num' phi_rad' phi_rad'.*180/pi]

phi_rtl = mod(phi_rad .* 2^n/(2*pi), 2^n)

%wo = pi/4;
%ws = 2*pi;
%fcw = (wo/ws)*2^n