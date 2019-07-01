close all
clear
clc
%% Set values of noises and signals
V2n    = (1e-4)^2;
ASig   = sqrt(2)*1.0;
FSig   = 100;
TSamp  = 1e-4;
TStop  = 0.1;
NSim   = 32;
rSeed=1454;
%sim('sig_noise')
Q = 8; A = 1; Phase = 0; DC = 0; fo = FSig; n = 10000; t     = (0:(n-1))./(1/TSamp);
r_amp = 0.01;
r     = -r_amp + (r_amp - -r_amp)*rand(1, n);
vout = round( 2^Q * (A * sin(2*pi*fo*t + Phase) + DC + r) ) ./ 2^Q;
%% Evaluate Fourier Transform and plot
N=max(size(vout));
%W = hanning(N);          %WN = ’Hanning Window’;
W = blackmanharris(N);   %WN = ’Blackman-Harris Window’;
%W = ones(N,1);           %WN = ’Rectangular Window’;
CG=sum(W)/N;             % Coherent Gain of the window
NG=sum(W.^2)/N;          % Noise Gain of the window
fbin=1/TStop;            % Frequency bin width
NF=fbin*NG/CG^2;         % Factor to be used when plotting an ideal PSD
                         % into the same plot%Calculate one-sided power spectral density
Y=vout.*W';               % Windowing
YF = abs(fft(Y))/CG/N;   % Transformed signal divided by coherent gain
f = (0:(N-1)/2)/TStop;   % Frequency Axis of half of the FFT
Pyy = 2*YF.^2;           % One-Sided Power Spectral Density
Pyy(1)=Pyy(1)/2;         % The DC component should not be doubled
for k=1:NSim-1,
  krSeed = 169+13*k;
  r     = -r_amp + (r_amp - -r_amp)*rand(1, n);
  vout = round( 2^Q * (A * sin(2*pi*fo*t + Phase) + DC + r) ) ./ 2^Q;
  Y=vout.*W';               % Windowing
  YF = abs(fft(Y))/(CG*N);   % Transformed signal divided by coherent gain
  Py = 2*YF.^2;            % One-Sided Power Spectral Density
  Py(1)=Pyy(1)/2;          % The DC component should not be doubled
  Pyy = Pyy+Py;
end

PG = 10*log10(N/2);
Pyy=Pyy/NSim;
PyydB=10*log10(Pyy(1:(N-1)/2+1)); % in dB
semilogx(f,PyydB)