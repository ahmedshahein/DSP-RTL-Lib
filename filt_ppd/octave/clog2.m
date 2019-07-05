function y = clog2(x)
  if (x<1)
    y = 0;
  else
    y = 1 + clog2(floor(x/2));
  end
  