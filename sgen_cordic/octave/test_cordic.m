clear
clc

mode_rotation   = false;
fxp             = true;
dtype           = 'signed';

n_iter  = 12;
x       = 1;
y       = 0;
z       = -70*pi/180;

gp_xy_width     = 24;
gp_z_width      = 16;
gp_angle_width  = 16;
gp_gain_width   = 24;

for i = 1 : n_iter,
    j = i-1;
    tan_lut(i)  = 2^-j;
    atan_lut(i) = atan(2^-j); % atand(2^-j);
    gain_lut(i) = 1/sqrt(1+2^(-2*j));
end
gain = prod(gain_lut);

tic
%if fxp
%    %Q_ATAN_LUT = quantizer('fixed', 'floor', 'wrap', [gp_angle_width gp_angle_width-2]);
%    atan_lut = quantize(atan_lut, gp_angle_width, "midtread", "signed").*2^(gp_angle_width-2);
%    %Q_GAIN = quantizer('fixed', 'floor', 'wrap', [gp_gain_width gp_gain_width-1]);
%    gain      = quantize(gain, gp_gain_width, "midtread", "signed")*2^(gp_gain_width-1);
%    %Q_XY = quantizer('fixed', 'floor', 'wrap', [gp_xy_width gp_xy_width-2]);
%    x = quantize(x, gp_xy_width, "midtread", "signed")*2^(gp_xy_width-2);
%    y = quantize(y, gp_xy_width, "midtread", "signed")*2^(gp_xy_width-2);
%    %Q_Z = quantizer('fixed', 'floor', 'wrap', [gp_z_width gp_z_width-2]);
%    z = quantize(z, gp_z_width, "midtread", "signed")*2^(gp_z_width-2);
%end
if fxp
    %Q_ATAN_LUT = quantizer('fixed', 'floor', 'wrap', [gp_angle_width gp_angle_width-2]);
    atan_lut = uquant(atan_lut, gp_angle_width, "s").*2^(gp_angle_width-2);
    %Q_GAIN = quantizer('fixed', 'floor', 'wrap', [gp_gain_width gp_gain_width-1]);
    gain      = uquant(gain, gp_gain_width, "s")*2^(gp_gain_width-1);
    %Q_XY = quantizer('fixed', 'floor', 'wrap', [gp_xy_width gp_xy_width-2]);
    x = floor(uquant(x, gp_xy_width, "s")*2^(gp_xy_width-2));
    y = floor(uquant(y, gp_xy_width, "s")*2^(gp_xy_width-2));
    %Q_Z = quantizer('fixed', 'floor', 'wrap', [gp_z_width gp_z_width-2]);
    z = floor(uquant(z, gp_z_width, 'xmax', pi/2, "s")*2^(gp_z_width-2));
end
toc

tic
x_init = x;
y_init = y;
z_init = z;

for i = 1 : n_iter,
    if i>1,
        if mode_rotation,
            if (z(i-1) >= 0),
                d = 1;
            else
                d = -1;
            end
        else
            if (y(i-1) < 0),
                d = 1;
            else
                d = -1;
            end
        end
    else
        if mode_rotation,
            if (z_init >= 0),
                d = 1;
            else
                d = -1;
            end
        else
            if (y_init < 0),
                d = 1;
            else
                d = -1;
            end
        end
    end
    
    if fxp
      if i == 1,
          x(i) = x_init - y_init*d*2^-(i-1);
          y(i) = y_init + x_init*d*2^-(i-1);
          z(i) = z_init - d*atan_lut(i);
      else
          x(i) = floor(x(i-1)) - floor(y(i-1)*d*2^-(i-1));
          y(i) = floor(y(i-1)) + floor(x(i-1)*d*2^-(i-1));
          z(i) = floor(z(i-1)) - floor(d*atan_lut(i));
      end
    else
      if i == 1,
          x(i) = x_init - y_init*d*2^-(i-1);
          y(i) = y_init + x_init*d*2^-(i-1);
          z(i) = z_init - d*atan_lut(i);
      else
          x(i) = x(i-1) - y(i-1)*d*2^-(i-1);
          y(i) = y(i-1) + x(i-1)*d*2^-(i-1);
          z(i) = z(i-1) - d*atan_lut(i);
      end
    end
end
toc

cos_z = x(end)*gain;
sin_z = y(end)*gain;

% cos_ref = cosd(z_init);
% sin_ref = sind(z_init);

if mode_rotation
    %[sin_ref, cos_qref] = cordicsincos(z_init*2^-(gp_z_width-2), n_iter);%*pi/180
    cos_ref = cos(z_init*2^-(gp_z_width-2));
    sin_ref = sin(z_init*2^-(gp_z_width-2));
    [cos_z*2^-(gp_xy_width+gp_gain_width-3) cos_ref]
    [sin_z*2^-(gp_xy_width+gp_gain_width-3) sin_ref]
else
    %[r, a] = cordiccart2pol(x_init*2^-(gp_xy_width-2), y_init*2^-(gp_xy_width-2), n_iter);
    a = sqrt( (x_init*2^-(gp_xy_width-2))^2 + (y_init*2^-(gp_xy_width-2))^2);
    r = atan((y_init*2^-(gp_xy_width-2))/(x_init*2^-(gp_xy_width-2))) + z_init*2^-(gp_z_width-2);
    [x(end)*gain*2^-(gp_xy_width+gp_gain_width-3) a]
    [(z(end)*2^-(gp_z_width-2)) r]
end

%fid = fopen('cordic_fxp.dat', 'w');
%for i = 1 : n_iter+1,
%  if i==1
%    fprintf(fid, 'x\ty\tz\n');
%  else
%    fprintf(fid, '%d\t%d\t%d\n', x(i-1), ...
%                                 y(i-1),...
%                                 z(i-1));
%  end
%end

var = [x' y' z'];
dlmwrite('cordic_fxp.dat', var, ' ');
%% EOF







% [cos_z cos_ref]% cos_mat]
% [sin_z sin_ref]% sin_mat]

% fid = fopen('cordic_fxp.dat', 'w');
% for i = 1 : n_iter+1,
%   if i==1
%     fprintf(fid, 'x\ty\tz\n');
%   else
%     fprintf(fid, '%d\t%d\t%d\n',  scale(x(i-1), gp_xy_width, dtype), ...
%                                       scale(y(i-1), gp_xy_width, dtype),...
%                                       scale(z(i-1), gp_z_width, dtype));
%   end
% end
%
% fclose(fid);





% Tcar = numerictype(1,gp_xy_width,gp_xy_width-2);
% Fcar = fimath('SumWordLength', gp_xy_width, 'SumFractionLength', gp_xy_width-2, 'SumMode', 'Specify');
% Trad = numerictype(1,gp_angle_width,gp_angle_width-3);
% Frad = fimath('SumWordLength', gp_angle_width, 'SumFractionLength', gp_angle_width-3, 'SumMode', 'Specify');
% if fxp
%   gain = fi(gain, 'NumericType', Tcar,'FiMath', Fcar);
%   x = fi( x, 'NumericType', Tcar,'FiMath', Fcar);
%   y = fi( y, 'NumericType', Tcar,'FiMath', Fcar);
%   z = fi( z, 'NumericType', Trad, 'FiMath', Frad);
%   atan_lut = fi(atan_lut, 'NumericType', Trad, 'FiMath', Frad);
% end

% if fxp
%   gain = sfi(gain, gp_gain_width, gp_gain_width-1);
%   x = sfi( x, gp_xy_width, gp_xy_width-2);
%   y = sfi( y, gp_xy_width, gp_xy_width-2);
%   z = sfi( z, gp_z_width, gp_z_width/2);
%   atan_lut = sfi(atan_lut, gp_angle_width, gp_angle_width/2);
% end


%lut_values = fi(sincos_val, 1, 16, 8);
% cordic_gain = fi(0.607259154319763, 1, 24, 23);
% angle_gain = fi(1, 1, 24, 22);
% nt = numerictype(1, 24, 8);
% fm = fimath(...
%     'RoundMode', 'floor',...
%     'OverflowMode', 'wrap',...
%     'ProductMode', 'FullPrecision', 'ProductWordLength', 32,...
%     'SumMode', 'FullPrecision', 'SumWordLength', 32,...
%     'CastBeforeSum', true);
% fival = fi(val, nt, fm);