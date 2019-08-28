function [oup, dbg] = cordic(defines, x, y, z)
% [oup, dbg] = cordic(n_iter, mode_rotation, lut_width, lut_depth, gain_width, xy_width, z_width, x, y, z)
% This is a behavioral model for CORDIC algorithm.
% P.S. The angles are based on DEGREE's.
% In case degree instead of radioan replace atan, cos and sin with atand, cosd, and sind
% GENERATE ATAN & GAIN LUTs'
n_iter        = defines.gp_nr_iter;
mode_rotation = defines.gp_mode_rot_vec; 
lut_width     = defines.gp_angle_width;
lut_depth     = defines.gp_angle_depth;
gain_width    = defines.gp_gain_width; 
xy_width      = defines.gp_xy_width;
z_width       = defines.gp_z_width;
testcase      = defines.testcase;

for i = 1 : lut_depth
    j           = i-1;
    tan_lut(i)  = 2^-j;
    atan_lut(i) = atan(2^-j);% RADIAN
    gain_lut(i) = 1/sqrt(1+2^(-2*j));
end
gain = 0.607252959138945;%prod(gain_lut);

x_init = x;
y_init = y;
z_init = z;

for i = 1 : n_iter,
    if i>1,
      % FUNCTIONAL MODE
        if mode_rotation,
            % ROTATION
            if (z(i-1) >= 0),
                d(i) = 1;
            else
                d(i) = -1;
            end
        else
            % VECTORING
            if (y(i-1) < 0),
                d(i) = 1;
            else
                d(i) = -1;
            end
        end
    else
        % INITIALIZATION MODE
        if mode_rotation,
            % ROTATION
            if (z_init >= 0),
                d(i) = 1;
            else
                d(i) = -1;
            end
        else
            % VECTORING
            if (y_init < 0),
                d(i) = 1;
            else
                d(i) = -1;
            end
        end
    end    
    % CORDIC ALGORITHM
    if i == 1,
        x(i) = x_init - y_init*d(i)*2^-(i-1);
        y(i) = y_init + x_init*d(i)*2^-(i-1);
        z(i) = z_init - d(i)*atan_lut(i);
    else
        x(i) = x(i-1) - y(i-1)*d(i)*2^-(i-1);
        y(i) = y(i-1) + x(i-1)*d(i)*2^-(i-1);
        z(i) = z(i-1) - d(i)*atan_lut(i);
    end
end

% CORDIC OUTPUT
if mode_rotation
    % ROTATION MODE
    cos_z = x(end)*gain
    sin_z = y(end)*gain

    cos_ref = cos(z_init)
    sin_ref = sin(z_init)
    
    %dat = [floor(cos_z*2^(xy_width+ceil(log2(n_iter)))) floor(sin_z*2^(xy_width+ceil(log2(n_iter))))];
    %ref = [floor(cos_ref*2^(xy_width+ceil(log2(n_iter)))) floor(sin_ref*2^(xy_width+ceil(log2(n_iter))))];
    
    dat = [floor(cos_z*2^(xy_width+ceil(log2(n_iter))-2)) floor(sin_z*2^(xy_width+ceil(log2(n_iter))-2))];
    ref = [floor(cos_ref*2^(xy_width+ceil(log2(n_iter))-2)) floor(sin_ref*2^(xy_width+ceil(log2(n_iter))-2))];
else
    % VECTORING MODE
    a_z = x(end)*gain
    r_z = z(end)
    a_ref = sqrt( x_init^2 + y_init^2)
    r_ref = atan(y_init/x_init) + z_init
    
    %dat = [floor(a_z*2^(xy_width+ceil(log2(n_iter)))) floor(r_z*2^(xy_width+ceil(log2(n_iter))))];
    %ref = [floor(a_ref*2^(xy_width+ceil(log2(n_iter)))) floor(r_ref*2^(xy_width+ceil(log2(n_iter))))];
    
    dat = [floor(a_z*2^(xy_width+ceil(log2(n_iter))-2)) floor(r_z*2^(z_width-2))];
    ref = [floor(a_ref*2^(xy_width+ceil(log2(n_iter))-2)) floor(r_ref*2^(z_width-2))];    
end

x_fxp = floor(x .* 2^(xy_width+ceil(log2(n_iter))-2));
y_fxp = floor(y .* 2^(xy_width+ceil(log2(n_iter))-2));
z_fxp = floor(z .* 2^(z_width-2));
d_fxp = d;
%% RESPONSE GENERATION
dbg = [x_fxp' y_fxp' z_fxp' d_fxp'];
oup = [dat' ref'];
filename_dbg = strcat("response_tc_",num2str(testcase,"%d"),"_dbg_mat.dat");
filename_oup = strcat("response_tc_",num2str(testcase,"%d"),"_oup_mat.dat");
csvwrite(filename_dbg,dbg, 'delimiter', ' ');
csvwrite(filename_oup,dat, 'delimiter', ' ');

%% ATAN LUT GENERATION
atan_lut_q  = uquant(atan_lut, lut_width, "s");
atan_lut_s  = floor(atan_lut_q.*2^(lut_width-2));
fid = fopen("atan_lut.v", "w");
for i = 1 : lut_depth,
  fprintf(fid, "assign atan_lut[%d] =  %d'sd%d;\n", i-1, lut_width, atan_lut_s(i));
end
fclose(fid);

%% STIMULI GENERATION  
disp("### INFO: Generating stimuli files.");
stimuli = [floor(x_init*2^(xy_width-2)) floor(y_init*2^(xy_width-2)) floor(z_init*2^(z_width-2))];
filename_inp = strcat("stimuli_tc_",num2str(testcase,"%d"),"_mat.dat");
csvwrite(filename_inp,stimuli,'delimiter',' ');
  
%[sin_mat, cos_mat] = cordicsincos(angle_degree*pi/180, n_iter);

%[cos_z cos_ref]% cos_mat]
%[sin_z sin_ref]% sin_mat]
