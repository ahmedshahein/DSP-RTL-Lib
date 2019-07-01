close all
clear
clc

% H(z) = ( SUM{i=0}{M.D-1} z^-i )^N
fs = 1;
NFFT = 1024;
%% CIC-1:
M = 1;
D = 8;
N = 3;

num = ones(1, M*D);
den = 1;
H1 = ( 1/(M*D) * filt(num, den) )^N;
[Hcic1, F1] = freqz(cell2mat(H1.num), cell2mat(H1.den), NFFT, 1);

figure
plot(F1, 10*log10(abs(Hcic1)), 'k', 'LineWidth', 2)
yaxis_lim = get(gca,'ylim');
hold on
plot([1/D 1/D], yaxis_lim, 'r--', 'LineWidth', 2)
hold on
plot([2/D 2/D], yaxis_lim, 'r--', 'LineWidth', 2)
hold on
plot([3/D 3/D], yaxis_lim, 'r--', 'LineWidth', 2)
grid on
tf_text = '$$H[z] = \sum_{i=0}^{D-1} z^{-i}$$';
title_text = strcat('N = ', {' '}, num2str(N), ', D = ', {' '},num2str(D));
title(strcat(tf_text, {' '}, ',', {' '},title_text), 'interpreter','latex')
%% CIC-2:
M = 1;
D = 4*8;
N = 3;

num = ones(1, M*D);
den = 1;
H2 = ( 1/(M*D) * filt(num, den) )^N;
[Hcic2, F2] = freqz(cell2mat(H2.num), cell2mat(H2.den), NFFT, 1);
%% invstigations
% M = 1;
% D = 4;
% N = 3;
% Dprev = 8;
% 
% num = ones(1, M*D);
% array = zero_insertion(num, Dprev);
% den = 1;
% H2 = ( 1/(M*D) * filt(array, den) );
% [Hcic2, F2] = freqz(cell2mat(H2.num), cell2mat(H2.den), NFFT, 1);

%% CIC-3:
M = 1;
D = 2*4*8;
N = 3;

num = ones(1, M*D);
den = 1;
H3 = ( 1/(M*D) * filt(num, den) )^N;
[Hcic3, F3] = freqz(cell2mat(H3.num), cell2mat(H3.den), NFFT, 1);

Hcic_cascade = abs(Hcic1) .* abs(Hcic2) .* abs(Hcic3);
%% CIC-64:
M = 1;
D = 64;
N = 3;

num = ones(1, M*D);
den = 1;
H = ( 1/(M*D) * filt(num, den) )^N;
[Hcic_64, F64] = freqz(cell2mat(H.num), cell2mat(H.den), NFFT, 1);
%%
figure
plot(F64, 10*log10(Hcic_cascade), 'k', 'LineWidth', 2)
hold on
plot(F64, 10*log10(abs(Hcic_64)), 'b', 'LineWidth', 2)
yaxis_lim = get(gca,'ylim');
hold on
plot([1/D 1/D], yaxis_lim, 'r--', 'LineWidth', 2)
grid on
axis([0 F64(end) -160 0])
legend('Cascade', 'Single')
tf_text = '$$H[z] = \sum_{i=0}^{D-1} z^{-i}$$';
title_text = strcat('N = ', {' '}, num2str(N), ', D = ', {' '},num2str(D));
title(strcat(tf_text, {' '}, ',', {' '},title_text), 'interpreter','latex')