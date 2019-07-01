close all
clear
clc
%% INPUT
%x       = [1 2 3 4 5 6 7 8 9 10]; 
%x = [0 1 0 0 0 0 0 0 0 0 0 5 35 -120 -77 0 0 1 1 1 1];
x = [0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0];
%% DESIGN PARAMETERS
N       = 3;    % FILTER ORDER
M       = 4;    % DOWNSAMPLE RATE
D       = 1;    % DIFFERENTIAL DELAYS
PHASE   = 0;  % DOWNSAMPLE PHASE
%% INTEGRATOR SECTION
x_cic = x;
% INITIALIZATION OF REGISTERS
reg_oup = zeros(1,N);
for i = 1 : length(x_cic),  
    for j = 1 : N,
        if j == 1,
            adder_oup(j) = x_cic(i) + reg_oup(j);
        else
            adder_oup(j) = adder_oup(j-1) + reg_oup(j);
        end        
    end
    reg_oup     = adder_oup;
    % CIC INTEGRATOR OUTPUT
    CIC_INTEGRATOR_OUP(i) = adder_oup(N); 
end
%% DOWNSAMPLE
x_cic = downsample(CIC_INTEGRATOR_OUP, M, PHASE);
%% COMB SECTION
clear adder_oup reg_oup
reg_oup = zeros(D, N);
for i = 1 : length(x_cic),
    % ADDER CELLS OUTPUT
    for j = 1 : N,
        if j == 1,
            adder_oup(j) = x_cic(i) - reg_oup(D, j);
        else
            adder_oup(j) = adder_oup(j-1) - reg_oup(D, j);
        end
    end
    % REGISTER INPUT & DELAY LINE
    reg_inp = [x_cic(i) adder_oup(1:N-1)];
    reg_oup = [reg_inp; reg_oup(1:D-1,:)];
    % CIC COMB OUTPUT
    CIC_COMB_OUP(i) = adder_oup(N);
end
%% CIC MODEL
% H(z) = ( [1 - z^-M.D]/[1 - z^-1] )^N
num         = zeros(1,M*D+1);
num(1)      =  1;
num(end)    = -1;
den         = [1 -1];
gain        = D*M;

H1 = ( 1/gain * filt(num, den) )^N
freqz(cell2mat(H1.num), cell2mat(H1.den))

% H(z) = ( SUM{i=0}{M.D-1} z^-i )^N
num = ones(1, M*D);
den = 1;
H2 = ( 1/(M*D) * filt(num, den) )^N
figure
freqz(cell2mat(H2.num), cell2mat(H2.den))
%% MATLAB REFERENCE DESIGN
f       = cicdesign(M, N, D);
data    = downsample( filter(f.B, f.A, x), M, PHASE)
%% EOF