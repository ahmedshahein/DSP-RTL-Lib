% butter_synth.m    12/9/17 Neil Robertson
% Find the coefficients of an IIR butterworth lowpass filter 
% using bilinear transform
%
% N= filter order
% fc= -3 dB frequency in Hz
% fs= sample frequency in Hz
% b = numerator coefficients of digital filter
% a = denominator coefficients of digital filter
%
function [b,a]= butter_synth(N,fc,fs);
%
if fc>=fs/2;
   error('fc must be less than fs/2')
end
% I.  Find poles of analog filter
k= 1:N;
theta= (2*k -1)*pi/(2*N);
pa= -sin(theta) + j*cos(theta);     % poles of filter with cutoff = 1 rad/s
%
% II.  scale poles in frequency
Fc= fs/pi * tan(pi*fc/fs);          % continuous pre-warped frequency
pa= pa*2*pi*Fc;                     % scale poles by 2*pi*Fc
%
% III.  Find coeffs of digital filter
% poles and zeros in the z plane
p= (1 + pa/(2*fs))./(1 - pa/(2*fs));      % poles by bilinear transform
q= -ones(1,N);                   % zeros
%
% convert poles and zeros to polynomial coeffs
a= poly(p);                   % convert poles to polynomial coeffs a
a= real(a);
b= poly(q);                   % convert zeros to polynomial coeffs b
K= sum(a)/sum(b);             % amplitude scale factor
b= K*b;