clear
clc

ROM_ADDR_WIDTH  = 5;
ROM_DEPTH       = 8*2^ROM_ADDR_WIDTH;
ROM_WIDTH       = 8;

A       = 1;
Offset  = 0;
Phase   = 0;

n = 32*8;
PA_WIDTH = 16;
fo = 50;
fs = 1e3;

sin_samples     = A * sin( 2*pi * [0:ROM_DEPTH-1] * (fo/fs) + Phase) + Offset;
sin_samples_full_int = round( (2^ROM_WIDTH-1) * sin_samples );

f = -fs/2:fs/n:fs/2-fs/n;
y=fftshift(fft(sin_samples));
w=window(@hanning,n);
yw = y'.*w;
plot(f,20*log10(abs(y./n)))

[value, index] = max(abs(y))
