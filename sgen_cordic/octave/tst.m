clear
clc

mode_rotation   = true;
fxp = true;

n_iter  = 12;
x       = 1;
y       = 0;
z       = 70;

gp_xy_width     = 8;
gp_z_width      = 8;
gp_angle_width  = 12;
gp_gain_width   = 8;

for i = 1 : n_iter,
    j = i-1;
    tan_lut(i)  = 2^-j;
    atan_lut(i) = atand(2^-j);
    gain_lut(i) = 1/sqrt(1+2^(-2*j));
end
gain = prod(gain_lut);

if fxp
  gain = round(gain * 2^(gp_gain_width-1));
  x = round( x * 2^(gp_xy_width-1) );
  y = round( y * 2^(gp_xy_width-1) );
  z = round( z * 2^(gp_z_width-1) );
  atan_lut = round(atan_lut .* 2^(gp_angle_width-1));
endif

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
    
    
    if i == 1,
        x(i) = x_init - floor(y_init*d*2^-(i-1));
        y(i) = y_init + floor(x_init*d*2^-(i-1));
        z(i) = z_init - floor(d*atan_lut(i));
    else
        x(i) = x(i-1) - floor(y(i-1)*d*2^-(i-1));
        y(i) = y(i-1) + floor(x(i-1)*d*2^-(i-1));
        z(i) = z(i-1) - floor(d*atan_lut(i));
    end
end

cos_z = x(end)*gain*2^-8;
sin_z = y(end)*gain*2^-8;

cos_ref = cosd(z(end));
sin_ref = sind(z(end));

%[sin_mat, cos_mat] = cordicsincos(angle_degree*pi/180, n_iter);

[cos_z cos_ref]% cos_mat]
[sin_z sin_ref]% sin_mat]