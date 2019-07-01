close all
clear
clc

nr_samples = 2^10;

p_decimation_factor = 4;
p_data_width = 8;
p_ccw = 1;
p_phase = 0;

%v = rand ("state");
rand ("state", 42);
r_min = -2^(p_data_width-1);
r_max =  2^(p_data_width-1);

r = floor(r_min + (r_max - r_min)*rand(1, nr_samples));

if ( (ceil(length(r)/p_decimation_factor)*p_decimation_factor) > length(r) ),
  extra_samples = zeros(1,(ceil(length(r)/p_decimation_factor)*p_decimation_factor)-length(r));
  r = [r extra_samples];
end

printf("Random constrinaed stimuli with min = %d, max = %d, mean = %f, std = %f\n", min(r), max(r), mean(r), std(r));

figure
hist(r)

data = zeros(1,length(r));
if (p_ccw)
  for (i = 1 : length(r)/p_decimation_factor)
    data( (i-1)*p_decimation_factor+1:i*p_decimation_factor ) = fliplr(r( (i-1)*p_decimation_factor+1:i*p_decimation_factor) );
  end
else
  data = r;
end

b = [5,10,15,20,25,30,25,20,15,10,5];
b = [0,-2,6,-17,37,-64,95,-119,127,-119,95,-64,37,-17,6,-2,0];

yy= downsample(filter(b,1,data),p_decimation_factor,p_decimation_factor-1-p_phase);

dlmwrite("stimuli_tc_03.dat", r, "\n");
%%
rtl = load("oup_tc_03.dat");
rtl = rtl(2:end);

for i = 1 : length(rtl),
  if (rtl(i) != yy(i))
    printf("### ERROR @%d, RTL = %d, Octave = %d\n", i, rtl(i), yy(i));
  end
end

figure
plot(yy)
hold on
plot(rtl, 'r')
