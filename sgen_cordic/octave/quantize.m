function q_data = quantize(r_data, Q, QType, DType)
  
  QLevels = quantizer(Q, QType, DType);
  q_data = zeros(1, length(r_data));
  for i = 1 : length(r_data)
    if (r_data(i) >= 0)
      [value,idx] = min(abs(r_data(i) - QLevels(length(QLevels)/2+1:end)));
      q_data(i) = QLevels(idx);
    else
      [value,idx] = min(abs(r_data(i) - QLevels(1:length(QLevels)/2)));
      q_data(i) = QLevels(idx);      
    endif
  endfor  