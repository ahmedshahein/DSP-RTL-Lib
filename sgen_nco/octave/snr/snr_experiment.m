close all
clear
clc

NFFT    = 2^12;
n       = 2^14;

fs      = 1e3;
fo      = 113;

A       = 0.5;
Phase   = 0;
DC      = 0;

t       = 0:1/fs:(n-1)/fs;
f       = -fs/2:fs/NFFT:fs/2-fs/NFFT;

sig     = 2*A * sin(2*pi*fo*t + Phase) + DC;

r       = -0.001 + (0.001 - -0.001)*rand(1,n);

sig_spectrum = ( fftshift(abs(fft(sig+r,NFFT))./NFFT) ).^2;

PG = 10*log10(NFFT/2);

figure
plot(t, sig)
grid on

figure
plot(f,10*log10(sig_spectrum))
grid on

%leak=1;
%[value, index] = max(sig_spectrum);
%sig_peak_index = find(sig_spectrum == value);
%noise_spectrum = sig_spectrum;
%noise_spectrum([sig_peak_index(1)-leak:sig_peak_index(1)+leak]) = 0;
%noise_spectrum([sig_peak_index(2)-leak:sig_peak_index(2)+leak]) = 0;
%
%
%sig_pwr = sum( sig_spectrum([sig_peak_index(1)-leak:sig_peak_index(1)+leak sig_peak_index(2)-leak:sig_peak_index(2)+leak]) );
%
%SNR = 10*log10( (sig_pwr)/var(noise_spectrum) ) - PG
inptSignal = sig+r;

N               = NFFT;%8192; % FFT length
leak            = 5; 
% considering a leakage of signal energy to 50 bins on either side of major freq component

fft_s           = fft(inptSignal,N)./N; % analysing freq spectrum
abs_fft_s       = abs(fft_s);

[~,p]           = max(abs_fft_s(1:N/2));
% Finding the peak in the freq spectrum

sigpos          = [p-leak:p+leak N-p-leak:N-p+leak];
% finding the bins corresponding to the signal around the major peak
% including leakage

sig_pow         = sum(abs_fft_s(sigpos)); % signal power = sum of magnitudes of bins conrresponding to signal
abs_fft_s([sigpos]) = 0; % making all bins corresponding to signal zero:==> what ever that remains is noise 
noise_pow       = sum(abs_fft_s); % sum of rest of componenents == noise power

SNR             = 10*log10(sig_pow/noise_pow)





%%%
%clear t sig
%q = 8;
%PA_WIDTH = 16;
%ROM_DEPTH_WIDTH = 8;
%ROM_DEPTH = 2^ROM_DEPTH_WIDTH;
%
%
%
%t       = (0:ROM_DEPTH-1)./ROM_DEPTH;
%sig     = 2*A * sin(2*pi*t + Phase) + DC;
%r = -0.001 + (0.001 - -0.001)*rand(1,ROM_DEPTH);
%sig_q = round(2^q * (sig+r))./2^q;
%fcw = round((fo/fs)*2^PA_WIDTH);
%
%phase_accu(1) = 0;
%for i = 2 : n
%    tmp = phase_accu(i-1) + fcw;
%    if (tmp <= (2^PA_WIDTH-1))
%        phase_accu(i) = tmp;
%    else
%        phase_accu(i) = tmp - (2^PA_WIDTH);
%    end
%end
%
%addr = floor(phase_accu * 2^-(PA_WIDTH-ROM_DEPTH_WIDTH));
%
%sine_nco = sig_q(addr+1);
%
%%sig_spectrum = abs(fftshift(fft(sine_nco,NFFT)))./NFFT;
%sig_spectrum = ( abs(fftshift(fft(sine_nco,NFFT)))./NFFT ).^2;%power: convert rms to power
%
%%AFFT = 2^9;
%%for i = 1 : AFFT
%%    a_spectrum(i,:) = fft(sine_nco,NFFT);
%%end
%%sig_spectrum = ( abs( fftshift(sum(a_spectrum)./AFFT)./NFFT ) ).^2;
%figure
%plot(sine_nco)
%grid on
%
%figure
%plot(f,10*log10(sig_spectrum))
%grid on
%
%leak=5;
%[value, index] = max(sig_spectrum);
%sig_peak_index = find(sig_spectrum == value);
%noise_spectrum = sig_spectrum;
%noise_spectrum([sig_peak_index(1)-leak:sig_peak_index(1)+leak]) = 0;
%noise_spectrum([sig_peak_index(2)-leak:sig_peak_index(2)+leak]) = 0;
%
%
%sig_pwr = sum( sig_spectrum([sig_peak_index(1)-leak:sig_peak_index(1)+leak sig_peak_index(2)-leak:sig_peak_index(2)+leak]) );
%
%SNR = 10*log10( (sig_pwr)/mean(noise_spectrum) )-PG
%
%figure
%plot(f, 10*log10(sig_spectrum))
%hold on
%plot(f, 10*log10(noise_spectrum))