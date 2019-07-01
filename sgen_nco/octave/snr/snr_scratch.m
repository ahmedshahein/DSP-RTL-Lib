close all
clear
clc

fs    = 1e3;
fo    = 200;

A     = 1;
Phase = 0;
DC    = 0;

n     = 2^16;

Q     = 8;

NFFT  = 2^12;

f     = -fs/2:fs/NFFT:fs/2-1/fs;
t     = (0:(n-1))./fs;

r_amp = 0.1;
r     = -r_amp + (r_amp - -r_amp)*rand(1, n);

sig   = round( 2^Q * (A * sin(2*pi*fo*t + Phase) + DC + r) ) ./ 2^Q;

%NFFT = 2^10;
AFFT = NFFT;

w = blackmanharris(NFFT);

sig_w = sig(1:NFFT) .* w';

CG = (1/NFFT) * sum(w); % Coherent Gain
NG = (1/NFFT) * sum(w.^2); % Noise Gain

sig_fft = abs( fft(sig_w, NFFT ) ) / (CG*NFFT); % Double-sided 

sig_dc = sig_fft(1);
%sig_fft(1) = [];
sig_spectrum = fftshift(sig_fft).^2;

for i = 1 : 32
  rand("seed", 169+13*i)
  r     = -r_amp + (r_amp - -r_amp)*rand(1, n);
  sig = round( 2^Q * (A * sin(2*pi*fo*t + Phase) + DC + r) ) ./ 2^Q;
  sig_w = sig(1:NFFT) .* w';
  sig_fft = abs( fft(sig_w, NFFT ) ) / (CG*NFFT);
  Py(i,:) = sig_fft.^2;
  %Pyy = Pyy + Py;
endfor

Pyy = sum(Py)/32;
PG = 10*log10(NFFT/2);
figure
plot(f, 10*log10(Pyy))

%figure
%plot(t, sig)
%
%
%PG = NFFT/2;
%
%sig_spectrum = ( abs( fftshift(fft(sig, NFFT)) )./NFFT ).^2;
%
%figure
%plot(f, 10*log10(sig_spectrum))

%leak = 5;
%[value, index] = max(sig_spectrum);
%sig_peak_idx = find(sig_spectrum == value);
%idx = [sig_peak_idx(1)-leak:sig_peak_idx(1)+leak sig_peak_idx(2)-leak:sig_peak_idx(2)+leak];
%sig_power = sig_spectrum(idx);
%
%noise_power = sig_spectrum;
%noise_power(idx) = [];
%
%10*log10(sum(sig_power))
%10*log10(mean(noise_power)) + 10*log10(PG)
