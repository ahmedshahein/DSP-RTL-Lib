close all
clear
clc

sel_angle_degree = 1;

%%
if sel_angle_degree,
    lut_tan         = atan(2.^-[0:7])*180/pi;
    scale_factor    = prod(cos(lut_tan*pi/180));
else
    lut_tan         = atan(2.^-[0:7]);
    scale_factor    = cos(lut_tan);
end
%% VECTORING MODE
x = 200;
y = 100;

L   = length(lut_tan);
xn  = zeros(1,L);
yn  = zeros(1,L);
phi = zeros(1,L);

for i = 1 : length(lut_tan),
    if i == 1,
        if y >= 0,
            xn(i)   = x + y;
            yn(i)   = y - x;
            phi(i)  = lut_tan(i);
        else
            xn(i)   = x - y;
            yn(i)   = y + x;
            phi(i)  = lut_tan(i);
        end
        fprintf('Xn\t\tYn\t\tPhi\n');
    else
        if yn(i-1) >= 0,
            xn(i)   = xn(i-1) + yn(i-1)*2^-(i-1);
            yn(i)   = yn(i-1) - xn(i-1)*2^-(i-1);
            phi(i)  = phi(i-1) + lut_tan(i);
        else
            xn(i)   = xn(i-1) - yn(i-1)*2^-(i-1);
            yn(i)   = yn(i-1) + xn(i-1)*2^-(i-1);
            phi(i)  = phi(i-1) - lut_tan(i);
        end
    end
    fprintf('%3.0f\t\t%4.0f\t%f\n', xn(i), yn(i), phi(i));
end

phi_ref             = atan(100/200)*180/pi;
hypotenuse_ref      = sqrt(100^2+200^2);

phi_cordic          = phi(end);
hypotenuse_cordic   = xn(end) * scale_factor;

fprintf('\n');
fprintf('REF    %f %f \n', phi_ref, hypotenuse_ref);
fprintf('CORDIC %f %f \n', phi_cordic, hypotenuse_cordic);
fprintf('\n');
%% ROTATION MODE
sel_angle_degree = 0;

if sel_angle_degree,
    lut_tan         = atan(2.^-[0:11])*180/pi;
    scale_factor    = prod(cos(lut_tan*pi/180));
else
    lut_tan         = atan(2.^-[0:11]);
    scale_factor    = prod(cos(lut_tan));
end

% ROTATION EXAMPLE
% x = 1;
% y = 0.125;
% angle = 67*pi/180;

% COMPUTING COS SIN EXAMPLE
x = 1;
y = 0;
angle = 67*pi/180;

%quadrant correction
if (angle < -pi/2) | (angle > pi/2),
    if angle < 0,
        angle = angle + pi;
    else
        angle = angle - pi;
    end
    %angle = -angle;
end

for i = 1 : length(lut_tan),
    if i == 1,
        
        xn(i)   = x;
        yn(i)   = y;
        phi(i)  = angle;
        
        fprintf('Xn\t\tYn\t\tPhi\n');
    elseif (i == 2),
        if phi(i-1) >= 0,
            xn(i)   = xn(i-1) - yn(i-1);
            yn(i)   = yn(i-1) + xn(i-1);
            phi(i)  = phi(i-1) - lut_tan(i-1);
        else
            xn(i)   = xn(i-1) + yn(i-1);
            yn(i)   = yn(i-1) - xn(i-1);
            phi(i)  = phi(i-1) + lut_tan(i-1);
        end
    else
        if phi(i-1) >= 0,
            xn(i)   = xn(i-1) - yn(i-1)*2^-(i-2);
            yn(i)   = yn(i-1) + xn(i-1)*2^-(i-2);
            phi(i)  = phi(i-1) - lut_tan(i-1);
        else
            xn(i)   = xn(i-1) + yn(i-1)*2^-(i-2);
            yn(i)   = yn(i-1) - xn(i-1)*2^-(i-2);
            phi(i)  = phi(i-1) + lut_tan(i-1);
        end
    end
    fprintf('%f\t\t%f\t%f\n', xn(i), yn(i), phi(i));
end

x_cordic = xn(end)*scale_factor;
y_cordic = yn(end)*scale_factor;

x_ref = (x*cos(angle) - y*sin(angle));
y_ref = (y*cos(angle) + x*sin(angle));

fprintf('\n');
fprintf('REF    %f %f\n', x_ref, y_ref);
fprintf('CORDIC %f %f\n', x_cordic, y_cordic)