function odata = calc_snr(idata)
  
%% FREQUENCY DOMAIN ANALYSIS
NFFT    = idata.NFFT;
fs      = idata.fs;
sig_r   = idata.sig;

f       = -fs/2:fs/NFFT:fs/2-fs/NFFT;
w       = blackmanharris(NFFT);
leak    = 0;%log2(NFFT);%10

sig_r_dft                     = abs(fft(sig_r(1:NFFT).*w', NFFT)) ./ NFFT;
sig_r_spectrum                = ( sig_r_dft ).^2;
sig_dc                        = [sig_r_spectrum(1:leak) sig_r_spectrum(end-leak:end)];
sig_r_spectrum(1:leak)        = [];
sig_r_spectrum(end-leak:end)  = [];
[value, index]                = max(sig_r_spectrum);
idx                           = find(sig_r_spectrum == value);

idx                           = [idx(1)-leak:idx(1)+leak idx(2)-leak:idx(2)+leak];
peak                          = sig_r_spectrum(idx);
noise                         = sig_r_spectrum;
noise(idx)                    = [];

SNR                           = sum(peak)/sum(noise);
SNR_dB                        = 10*log10(SNR);

odata.SNR       = SNR;
odata.SNR_dB    = SNR_dB;
odata.dc_pwr    = sum(sig_dc);
odata.sig_pwr   = sum(peak);
odata.noise_pwr = sum(noise);

PG = 10*log10(NFFT/2);

f = -fs/2:fs/NFFT:fs/2-fs/NFFT;
figure
plot(f, 10*log10(fftshift(sig_r_dft)))
%n = length(data);
%f = -fs/2:fs/n:fs/2-fs/n;
%y = fftshift(fft(data));
%yn = y./n;
%figure
%plot(f,20*log10(abs(yn)))
%
%pos_spectrum = abs(yn(ceil(n/2):end));
%[value, index] = max(pos_spectrum);
%noise_spectrum = pos_spectrum;
%noise_spectrum(index-2:index+2) = [];
%mean_noise = mean(noise_spectrum);
%SNR = 20*log10(value/mean_noise);
%
%%SNR_ref = 6.02*q;