%close all
clear
clc

%% SIGNAP PARAM
fs      = 1e3;
fo      = 33;
A       = 0.35;
Phase   = 0;
DC      = 0;
n       = 2^16;
t       = 0:1/fs:(n-1)/fs;
sig     = A * sin(2*pi*fo*t + Phase) + DC;

%% NOISE PARAM
Ar      = 0.0001;
r       = -Ar + (Ar - -Ar)*rand(1,n);

%% SINSOIDAL SIGNAL
Q = 12;
sig_r   = round( 2^Q * (sig + r) )./2^Q;
%sig_r   = sig + r;
%sig_q = quantize(sig_r, Q, "midtread");

%% TIME DOMAIN ANALYSIS
% AVERAGE - MEAN
sig_avg   = sum(sig)/n;   % mean(sig)
r_avg     = sum(r)/n;     % mean(r)
sig_r_avg = sum(sig_r)/n; % mean(sig_r)
% VARIANCE - NOISE POWER
sig_var   = sum((sig - sig_avg).^2)/n;        % var(sig)
r_var     = sum((r - r_avg).^2)/n;            % var(r)
sig_r_var = sum((sig_r - sig_r_avg).^2)/n;    % var(sig_r)
% STANDARD DEVIATION
sig_std   = sqrt(sum((sig - sig_avg).^2)/n);  % std(sig)
r_std     = sqrt(r_var);                      % std(r)
sig_r_std = std(sig_r);
% POWER
sig_pwr   = sum(sig.^2)/n
r_pwr     = sum(r.^2)/n
sig_r_pwr = sum(sig_r.^2)/n
% RMS
sig_rms   = sqrt(sum(sig.^2)/n) % A/sqrt(2)
r_rms     = sqrt(sum(r.^2)/n)
sig_r_rms = sqrt(sum(sig_r.^2)/n)
% DC POWER
sig_dc    = sig_avg^2
r_dc      = r_avg^2
sig_r_dc  = sig_r_avg^2

% SNR LINEAR
SNR = sig_pwr/r_pwr
SNR = sig_var/r_var
% SNR dB
SNR_dB = 10*log10(SNR)
SNR_dB = 20*log10(sig_rms/r_rms)
SNR_dB = 20*log10(sig_std/r_std)

%% FREQUENCY DOMAIN ANALYSIS
NFFT    = 2^10;
f       = -fs/2:fs/NFFT:fs/2-fs/NFFT;
w       = blackmanharris(NFFT);
leak    = 10;%log2(NFFT);

sig_r_dft       = abs(fft(sig_r(1:NFFT).*w', NFFT)) ./ NFFT;
sig_r_spectrum  = ( sig_r_dft ).^2;
sig_dc          = [sig_r_spectrum(1:leak) sig_r_spectrum(end-leak:end)];
sig_r_spectrum(1:leak) = [];
sig_r_spectrum(end-leak:end) = [];
[value, index]  = max(sig_r_spectrum);
idx             = find(sig_r_spectrum == value);

idx   = [idx(1)-leak:idx(1)+leak idx(2)-leak:idx(2)+leak];
peak  = sig_r_spectrum(idx);
noise = sig_r_spectrum;
noise(idx) = [];

SNR     = sum(peak)/sum(noise)
SNR_dB  = 10*log10(SNR)
PG = 10*log10(NFFT/2)
SNR_Q_dB = 6.02*Q + 1.76
BW=fs/8;
QPG = 10*log10(fs/(2*BW))