function q_data = quantize(r_data, Q, QType)
  % midtread has 0
  QLevels = quantizer(Q, QType);
  for i = 1 : length(r_data)
    if (r_data(i) >= 0)
      [value,idx] = min(abs(r_data(i) - QLevels));
      q_data(i) = QLevels(idx);
    else
      [value,idx] = min(abs(r_data(i) - QLevels));
      q_data(i) = QLevels(idx);      
    endif
  endfor  