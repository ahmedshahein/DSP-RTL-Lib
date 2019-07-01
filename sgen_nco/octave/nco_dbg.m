%close all
%clear
%clc

ROM_ADDR_WIDTH  = 5;
ROM_DEPTH       = 8*2^ROM_ADDR_WIDTH;
ROM_WIDTH       = 8;

A       = 1;
Offset  = 0;
Phase   = 0;

sin_samples     = A * sin( 2*pi * [0:ROM_DEPTH-1]./ROM_DEPTH + Phase) + Offset;
sin_samples_int = round( (2^ROM_WIDTH-1) * sin_samples );


n = 2^9;
PA_WIDTH = 16;
fo = 50;
fs = 1e3;

fcw = round( (fo/fs) * 2^PA_WIDTH );

phase_accu(1) = 0;
for i = 2 : n
  tmp = phase_accu(i-1) + fcw;
  if (tmp <= (2^PA_WIDTH-1))
    phase_accu(i) = tmp;
  else
    phase_accu(i) = tmp - (2^PA_WIDTH-1);
  endif
endfor

pa_bin    = dec2bin(phase_accu,PA_WIDTH);
%addr_bin  = pa_bin(:,4:4+ROM_ADDR_WIDTH-1);
addr_bin  = pa_bin(:,1:1+log2(ROM_DEPTH)-1);
addr_dec  = bin2dec(addr_bin);
%addr_dec  = floor(phase_accu*2^-8);%phase_accu;%

sin_nco = sin_samples_int(addr_dec+1);

f = -fs/2:fs/n:fs/2-fs/n;
y=fftshift(fft(sin_nco));
w=window(@hanning,n);
%yw = y'.*w;
%plot(f,10*log10(abs(y)))
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%ROM_ADDR_WIDTH  = 5;
%ROM_DEPTH       = 8*2^ROM_ADDR_WIDTH;
%ROM_WIDTH       = 8;

%A       = 1;
%Offset  = 0;
%Phase   = 0;

%n = 2^16;
%PA_WIDTH = 16;
%fo = 50;
%fs = 1e3;

t = 0:1/fs:(n-1)/fs;
sin_samples     = A * sin( 2*pi * fo * t + Phase) + Offset;
sin_samples_full_int = round( (2^ROM_WIDTH-1) * sin_samples );

f = -fs/2:fs/n:fs/2-fs/n;
y=fft(sin_samples_full_int);
y=fftshift(y);
w=window(@hanning,n);
yw = y'.*w;
figure
plot(f,10*log10(abs(y)))