function q_data = quantize(r_data, Q, QType)
  
  QLevels = quantizer(Q, QType);
  for i = 1 : length(r_data),
    if (r_data(i) >= 0),
      for j = length(QLevels)/2 : length(QLevels),
        if (r_data(i) >= QLevels(end))
          q_data(i) = QLevels(end);
        elseif (r_data(i)>=QLevels(j) && r_data(i)<QLevels(j+1))
          q_data(i) = QLevels(j);
        endif
      endfor
    else
      for j = 1 : length(QLevels)/2,
        if (r_data(i) <= QLevels(1))
          q_data(i) = QLevels(1);
        elseif (r_data(i)<=QLevels(j) && r_data(i)>QLevels(j-1))
          q_data(i) = QLevels(j);
        endif   
      endfor
    endif  
  endfor
  