close all
clear
clc

fs      = 73.1e3;
f_sweep = 330:17:fs/2;

for i = 1 : length(f_sweep)
%% SIGNAP PARAM
%fs      = 1e3;
fo      = f_sweep(i);
A       = 0.15;
Phase   = 0;
DC      = 0;
n       = 2^16;
t       = 0:1/fs:(n-1)/fs;
sig     = A * sin(2*pi*fo*t + Phase) + DC;

%% NOISE PARAM
Ar      = 0.001;
r       = -Ar + (Ar - -Ar)*rand(1,n);

%% SINSOIDAL SIGNAL
sig_r   = sig + r;

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
sig_pwr   = sum(sig.^2)/n;
r_pwr     = sum(r.^2)/n;
sig_r_pwr = sum(sig_r.^2)/n;
% RMS
sig_rms   = sqrt(sum(sig.^2)/n); % A/sqrt(2)
r_rms     = sqrt(sum(r.^2)/n);
sig_r_rms = sqrt(sum(sig_r.^2)/n);
% DC POWER
sig_dc    = sig_avg^2;
r_dc      = r_avg^2;
sig_r_dc  = sig_r_avg^2;

% SNR LINEAR
SNR = sig_pwr/r_pwr;
SNR = sig_var/r_var;
% SNR dB
SNR_dB = 10*log10(SNR);
SNR_dB = 20*log10(sig_rms/r_rms);
SNR_dB = 20*log10(sig_std/r_std);

NFFT = 2^15;

idata.NFFT = NFFT;
idata.fs = fs;
idata.sig = sig_r;

odata = calc_snr(idata);

err(i) = odata.SNR_dB - SNR_dB;

endfor

plot(err)