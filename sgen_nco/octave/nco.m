function y2 = nco(param)
% Phase_increment = (F0*2^N)/Fs
% Phase_offset = (pi/2)*2^N/(2*pi), offset by pi/2
fo    = param.fo;
fs    = param.fs;
fcw   = fo/fs;
%example NCO parameters
n   = param.nr_of_samples;            %number of test samples
A   = 2^param.gp_rom_width -1 ;       %max amplitude, amplitude resolution 16 bit signed
M   = 2^param.gp_phase_accu_width;    %NCO accumulator phase resolution
inc = floor(M*fcw);                   %NCO accumulator phase increment 
k   = 2^param.gp_rom_depth;           %lut phase resolution (lut size), may equal M

%single equation for NCO bit true model
y1 = round(A*sin(2*pi*round(k*mod((0:n-1)*inc/M,M))/k));      
%y = sin(2*pi*round(k*mod((0:n-1)*inc/M,M))/k); 
%yq = quantize(y, param.gp_rom_width, "midtread"); 
%ys = round(A*yq);
%y1=ys; 
%%%%%%%%%%%%%%%%%%%%%%%%% equivalent code %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
lsb   = log2(M) - log2(k);                 %LSBs discarded when addressing
lut   = round(A*sin(2*pi*(0:k-1)/k)); %lut, one cycle sine data
%lut   = round(A*quantize(sin(2*pi*(0:k-1)/k),param.gp_rom_width,"midtread"));      %lut, one cycle sine data

ptr   = 0; 
addr  = 0;
for i = 1:n 
    y2(i)           = lut(addr+1);          %add 1 for matlab LUT
    ptr             = mod(ptr + inc, M);      %phase accumulator(ramp)
    addr            = floor(ptr/2^lsb);      %discard LSBs %%round
    addr(addr >= k) = addr - k;   %check address overflow
end

%compare
plot(y1);hold;
plot(y2,'r--')
plot(y1 - y2,'g--')
%% EOF



%ROM_ADDR_WIDTH  = param.gp_rom_depth;
%ROM_DEPTH       = 2^ROM_ADDR_WIDTH;
%ROM_WIDTH       = param.gp_rom_width;
%
%A               = param.ampl;
%Offset          = param.offset;
%Phase           = param.phase;
%
%n               = param.nr_of_samples;
%PA_WIDTH        = param.gp_phase_accu_width;
%fo              = param.fo;
%fs              = param.fs;
%
%sin_samples     = A * sin( 2*pi * [0:ROM_DEPTH-1]./ROM_DEPTH + Phase) + Offset;
%cos_samples     = A * cos( 2*pi * [0:ROM_DEPTH-1]./ROM_DEPTH + Phase) + Offset;
%sin_samples_int = round( (2^ROM_WIDTH-1) * sin_samples );
%cos_samples_int = round( (2^ROM_WIDTH-1) * cos_samples );
%
%%rand ("seed", 156*13);
%%DA = PA_WIDTH - ROM_ADDR_WIDTH + 1;
%%dither = round( 2^DA * (0 + (1 - 0)*rand(1, n)) );
%
%fcw = floor( (fo/fs) * 2^PA_WIDTH );
%
%phase_accu(1) = 0;
%for i = 2 : n
%  tmp = phase_accu(i-1) + fcw;% + dither(i);
%  if (tmp <= (2^PA_WIDTH-1))
%    phase_accu(i) = tmp;
%  else
%    phase_accu(i) = tmp - (2^PA_WIDTH-1);
%  endif
%endfor
%
%%pa_bin    = dec2bin(phase_accu,PA_WIDTH);
%%addr_bin  = pa_bin(:,4:4+ROM_ADDR_WIDTH-1);
%%addr_bin  = pa_bin(:,1:1+log2(ROM_DEPTH)-1);
%%addr_dec  = bin2dec(addr_bin);
%addr_dec  = floor((phase_accu)*2^-(PA_WIDTH-ROM_ADDR_WIDTH)) + 1;
%
%sin_nco = sin_samples_int(addr_dec);
%
%%f = -fs/2:fs/n:fs/2-fs/n;
%%y_nco = fftshift(fft(sin_nco));
%%y_nco_psd = 10*log10(abs(y_nco));
%%%w=window(@hanning,n);
%%%yw = y'.*w;
%%plot(f,10*log10(abs(y_nco)))
%
%idata.NFFT = param.NFFT;
%idata.fs = fs;
%idata.sig = sin_nco;
%
%odata = [];%calc_snr(idata);
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%t = 0:1/fs:(n-1)/fs;
%%sin_samples     = A * sin( 2*pi * fo * t + Phase) + Offset;
%%sin_samples_full_int = round( (2^ROM_WIDTH-1) * sin_samples );
%%
%%f = -fs/2:fs/n:fs/2-fs/n;
%%y_ref = fftshift(fft(sin_samples_full_int));
%%y_ref_psd = 10*log10(abs(y_ref));
%%w=window(@hanning,n);
%%yw = y'.*w;
%%figure
%%plot(f,10*log10(abs(y_ref)))
%
%%data.ref = sin_samples_full_int;
%data.nco = sin_nco;
%%data.ref_psd = y_ref_psd;
%%data.nco_psd = y_nco_psd;
%
%%EOF