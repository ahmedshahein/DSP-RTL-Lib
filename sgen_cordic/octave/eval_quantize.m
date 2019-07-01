clear
clc

n = 2^22;
Q = 16;
QType = "midtread";
DType = "signed";
r = -1 + (1 - -1)*rand(1,n);

tic
q_data = quantize(r, Q, QType, DType);
toc