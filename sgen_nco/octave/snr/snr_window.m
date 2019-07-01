% sdex.m
% Determining the Signal-to-Noise Ratio of a signal.
% Hanspeter Schmid, May 2011 (updated August 2012)
% Generate an interesting signal (sigma-delta bitstream)
TSamp = 1e-6; t = (0:TSamp:2^10*TSamp)';
fsig = 14400.55; % Constructed to show some scallop loss
asig = 0.8; % Signal magnitude in V
vn = 1/300; % Total integrated noise in Vrms
vin = asig*sin(2*pi*fsig*t)+randn(size(t))*vn;
bout = ones(size(vin)); qin = 0; regin = vin(1); regout = 0;
for k=2:max(size(t))
if qin>=0
qout=1;
else
qout=-1;
end
bout(k)=qout;
qin = regin;
regin = vin(k)-qout+qin;
end
% Calculate an 8-times averaged spectrum with pwelch
nx = max(size(bout)); na = 8;
w = blackmanharris(floor(nx/na));
[Pxx,f] = pwelch(bout,w,0,[],1/TSamp);
% Calculate the spectrum parameters
fbin = f(2)-f(1);
CG = sum(w)/(nx/na);
NG = sum(w.^2)/(nx/na);
% Calculate the indices of the Signal, harmonics, band edge
isig = round(fsig/fbin)+1;
ih3 = round(3*fsig/fbin)+1;
ih5 = round(5*fsig/fbin)+1;
ibw = round(2500/fbin)+1;
% Plot and mark the above
loglog(f,Pxx);
hold on
itmp = (isig-5:isig+5)'; plot(f(itmp),Pxx(itmp),'r');
itmp = (ih3-4:ih3+4)'; plot(f(itmp),Pxx(itmp),'r');
itmp = (ih5-4:ih5+4)'; plot(f(itmp),Pxx(itmp),'r');
plot(f(ibw:end),Pxx(ibw:end),'g');
hold off
a=axis(); a(1)=f(1); a(2)=f(end); axis(a);
xlabel('Frequency [Hz]');
ylabel('Power Density [Vˆ2/Hz]');
% and now present a few calculations:
fprintf('\nCalculations from the spectrum\n')
fprintf('==============================\n\n')
fprintf('1. Measuring the signal magnitude:\n\n')
srmt = asig/sqrt(2);
fprintf(' Theoretical value: %1.5f Vrms\n',srmt)
srms = sqrt(sum(Pxx(isig-5:isig+5)*fbin));
fprintf(' Signal spectrum integrated: %1.5f Vrms\n',srms)
srmsp = sqrt( Pxx(isig) * NG*fbin/CG^2 );
fprintf(' Maximum read off spectrum: %1.5f Vrms\n',srmsp)
scl = 20*log10(srmt/srmsp);
fprintf(' Scallop loss: %1.5f dB\n\n',scl)
fprintf('2. Measuring the noise floor:\n\n')
nth = vn/sqrt(max(f));
fprintf(' Theoretical value: %2.3f uV/sqrt(Hz)\n',nth*1e6)
inmax = isig-20;
nsum = sqrt(sum(Pxx(1:inmax)*fbin)) / sqrt(f(inmax));
fprintf(' Signal spectrum integrated: %2.3f uV/sqrt(Hz)\n',nsum*1e6)
navg = sqrt(mean(Pxx(1:inmax)));
fprintf(' pwelch output averaged: %2.3f uV/sqrt(Hz)\n',navg*1e6)
fprintf('\n3. Signal, Distortion and Noise:\n\n')
% This calculation requires a trick with a mask such that the
% Noise summation does not use the Signal- and Distortion as well
imask = ones(size(Pxx));
imask(ibw+1:end)=0;
itmp = isig-5:isig+5; imask(itmp)=0; Ps = 10*log10(sum(Pxx(itmp)*fbin));
fprintf(' Signal power: %8.3f dB re 1 Vrms\n',Ps)
itmp = ih3-4:ih3+4; imask(itmp)=0; P3 = 10*log10(sum(Pxx(itmp)*fbin));
fprintf(' Third-order distortion: %8.3f dB re 1 Vrms\n',P3)
itmp = ih5-4:ih5+4; imask(itmp)=0; P5 = 10*log10(sum(Pxx(itmp)*fbin));
fprintf(' Fifth-order distortion: %8.3f dB re 1 Vrms\n',P5)
Pn = 10*log10(sum(Pxx.*imask*fbin));
fprintf(' Noise from 0 to 2500Hz: %8.3f dB re 1 Vrms\n',Pn)