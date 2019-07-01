function y = scale(x, w, dtype)
  q_data = quantize(x, w, "midtread", dtype);
  if (strcmp(dtype, "signed"))
    y = floor( x .* 2^(w-1) );
  else
    y = floor( x .* 2^w );
  endif
  