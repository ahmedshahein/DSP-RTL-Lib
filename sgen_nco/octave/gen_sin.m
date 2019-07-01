close all
clear
clc


A = 1;
Phase = 0;
Offset = 0;
fo = 237;
fs = 1e3;
c = 2^14;
q = 8;
%n=2^9;%c*fs/fo;%length(sin_samples);
%t = 0:1/fs:(c/fo)-1/fs;
%n = length(t);
n=2^8;
t = 0:1/fs:(n-1)/fs;
%t = [0:n-1]./fs;
%t = [0:n-1]./n;
%t = [0:n-1];
sin_samples     = A * sin( 2*pi * fo .* t + Phase) + Offset;
sin_samples_q = quantize(sin_samples, q, "midtread");
sin_samples_full_int = round( (2^q) .* sin_samples_q );

%f = -fs/2:fs/n:fs/2-fs/n;
%y = fftshift(fft(sin_samples_q));
%yn = y./n;
%%w = window(@hanning,n);
%%yw = y'.*w;
%figure
%plot(f,20*log10(abs(y./n)))

SNR = calc_snr(sin_samples_q, fs)
%pos_spectrum = abs(yn(ceil(n/2):end));
%[value, index] = max(pos_spectrum);
%noise_spectrum = pos_spectrum;
%noise_spectrum(index-2:index+2) = [];
%mean_noise = mean(noise_spectrum);
%SNR = 20*log10(value/mean_noise)

%SNR_ref = 6.02*q;