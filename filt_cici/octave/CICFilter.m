function [FilteredData Hcic] = CICFilter(M, N, R, P, Fs, Data, Type)
% [FilteredData Hcic] = CICFilter(M, N, R, Fs, Data)
%
% This function formulate the CIC transfer function, which can be used to
% filter the filter input data and plot the filter response with both input
% and output spectrums. It is integrated with the 
% 'CascadedCICCompensationFilter' function.
%
%   M:              Differntial delay
%   N:              Filter order
%   R:              Decimation factor
%   P:              Downsample phase
%   Fs:             Sampling frequency
%   Data:           Filter input data
%
%   FilteredData:   Filtered and downsampled output data
%   Hcic:           CIC filter transfer function
%
% Ref: GUI Based Decimation Filter Design Toolbox for Multi Standard Wireless Transceveris
%
% Source MSD-Toolbox on MathWorks by Ahmed hahein

Num     = ones(1,R*M);
Den     = 1;
H       = filt(Num,Den,1/Fs);
Hcic    = (H^N);%/((R*M)^N);
Num_CIC = cell2mat(Hcic.num);
Den_CIC = cell2mat(Hcic.den);
if strcmp(Type, 'i') || strcmp(Type, 'I') || strcmp(Type, 'interpolate')
  FilteredData = filter(Num_CIC,Den_CIC,upsample(Data, R, P));disp("### INFO: Interpolation process!");
else
  FilteredData = downsample(filter(Num_CIC,Den_CIC,Data),R, P);
end

