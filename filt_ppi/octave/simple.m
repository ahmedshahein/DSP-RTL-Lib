clear
clc

x = [10 11 12 13];
h = [-2 0 2 5 8 11 11 8 5 2 0 -2];

data_up = upsample(x, 4, 0);

y = filter(h, 1, data_up)