close all
clear
clc

n = 100000;
q = 8;

%Q = quantizer('Mode', 'fixed', 'Roundmode', 'nearest', 'Overflowmode', 'wrap', 'Format', [q q-1]);

fs = 1e3;
fo = 100;
T=1000;
t = 0:1/fs:T-1/fs;% I changed to be more understandable 
t_l=length(t);
r = 0.01*randn(1,t_l);
sig = sin(2*pi*fo*t);
sig_r = round( 2^q * (sig + r) )./2^q;

f = -fs/2:fs/T:fs/2-1/fs;
y = fftshift(fft(sig_r, T));
yn = y./T;
sig_spectrum = abs(yn);

[value, index] = max(sig_spectrum);
sig_peak_index = find(sig_spectrum == value);
noise_spectrum = sig_spectrum;
noise_spectrum([sig_peak_index(1)-1:sig_peak_index(1)+1]) = mean(noise_spectrum)/sqrt(T);% I normalized over sqrt the number of samples
noise_spectrum([sig_peak_index(2)-1:sig_peak_index(2)+1]) = mean(noise_spectrum)/sqrt(T);

figure
plot(sig_r)

figure
plot(f, sig_spectrum)
hold on
plot(f, noise_spectrum)

figure
plot(f, 20*log10(sig_spectrum))
hold on
plot(f, 20*log10(noise_spectrum))

SNR = 10*log10( 2*(value)^2/(mean(noise_spectrum)^2) )-10*log10(T)% I did the same here
SNR_var = 10*log10(2*value^2/abs(var(sig_r)-2*value^2))

snr(sig_r,sig_r - sig)