function [cos_z, sin_z] = cordic(n_iter, mode_rotation, x, y, z, fxp, lut_width)

for i = 1 : n_iter,
    j           = i-1;
    tan_lut(i)  = 2^-j;
    atan_lut(i) = atand(2^-j);
    gain_lut(i) = 1/sqrt(1+2^(-2*j));
end
gain = prod(gain_lut);

if fxp
  %gain = floor(gain * 2^());
  atan_lut = round(atan_lut .* 2^(lut_width-1));
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
        x(i) = x_init - y_init*d*2^-(i-1);
        y(i) = y_init + x_init*d*2^-(i-1);
        z(i) = z_init - d*atan_lut(i);
    else
        x(i) = x(i-1) - y(i-1)*d*2^-(i-1);
        y(i) = y(i-1) + x(i-1)*d*2^-(i-1);
        z(i) = z(i-1) - d*atan_lut(i);
    end
end

cos_z = x(end)*gain;
sin_z = y(end)*gain;

cos_ref = cosd(z);
sin_ref = sind(z);

%[sin_mat, cos_mat] = cordicsincos(angle_degree*pi/180, n_iter);

%[cos_z cos_ref]% cos_mat]
%[sin_z sin_ref]% sin_mat]