function f = cicdesign(R, N, M)
%CICDESIGN N-stage decimate by R CIC-filter design
%  CICDESIGN allows decimation factor and number of stages to be specified
%  for the "simulated" design of a CIC filter. The FIR filter returned has
%  the magnitude and phase response of an "actual" CIC filter but not the
%  decimation.
%
%  F = CICDESIGN(R, N, M) returns a filter structure which contains the
%  numerator coefficients (B), the denominator coefficients (always A=1)
%  and the decimation factor (R).
%  
%  where:
%  R is the decimation factor
%  N is the number of stages of the CIC filter
%  M is the differential delay parameter
%
%  To actually use this filter, the data has to be passed through CICFILTER
%  instead of Matlab's FILTER. CICFILTER uses Matlab's FILTER function but
%  will also decimate the output according to the factor, R.
%
%
%  Author: Shen-Hsiao TAN
%  Date  : Oct 09
%


%% Form the single-stage CIC filter with decimation R and delay M
%
RM      = R*M;
B       = zeros(1, RM+1);
B(1)    = 1;
B(RM+1) = -1;
A       = [ 1 -1 ];


%% Create the cascade N stages of the filter
%
[h t] = impz(B, A);     % Impulse response of single-stage CIC filter
FinalImpResp = h;
if N > 1
    for count=2:N
        FinalImpResp = conv(FinalImpResp, h);
    end
end
f.B = FinalImpResp;
f.A = 1;
f.R = R;
