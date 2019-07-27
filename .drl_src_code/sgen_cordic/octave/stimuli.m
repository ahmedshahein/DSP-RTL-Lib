close all
clear
clc

defines.gp_mode_rot_vec            = 0,
defines.gp_impl_unrolled_iterative = 0,
defines.gp_nr_iter                 = 16,
defines.gp_angle_width             = 16,
defines.gp_angle_depth             = 16,
defines.gp_xy_width                = 8,
defines.gp_z_width                 = 8;

[cos_z, sin_z] = cordic(n_iter, mode_rotation, x, y, z, fxp, lut_width);

