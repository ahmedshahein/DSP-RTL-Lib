function q_data = quantize(r_data, Q, QType, DType)
  
  if length(r_data) > 1
    if mod(length(r_data), 2) == 0, % EVEN
      if ( r_data(1:length(r_data)/2) == r_data(length(r_data)/2+1:end) )
        arr_type = "even";
        half_array = r_data(1:length(r_data)/2);
        disp("### INFO: The input array has even symmetry!");
      else
        arr_type = "nosymm";
        half_array = r_data;
        disp("### INFO: The input array has even asymmetry");
      endif
    else
      if ( r_data(1:floor(length(r_data)/2)) == r_data(ceil(length(r_data)/2)+1:end) )
        arr_type = "odd";
        half_array = r_data(1:ceil(length(r_data)/2));
        disp("### INFO: The input array has odd asymmetry!");
      else
        arr_type = "nosymm";
        half_array = r_data;
      endif      
    endif
  endif
  
  QLevels = quantizer(Q, QType, DType);
  q_data_half = zeros(1, length(half_array));
  
  for i = 1 : length(half_array)
    if (half_array(i) >= 0)
      [value,idx] = min(abs(half_array(i) - QLevels(length(QLevels)/2+1:end)));
      q_data_half(i) = QLevels(length(QLevels)/2+idx);
    else
      [value,idx] = min(abs(half_array(i) - QLevels(1:length(QLevels)/2)));
      q_data_half(i) = QLevels(idx);      
    endif
  endfor  
  
  if strcmp(arr_type, "nosymm")
    q_data = q_data_half;
  elseif strcmp(arr_type, "even")
    q_data = [q_data_half fliplr(q_data_half)];
  elseif strcmp(arr_type, "odd")
    q_data = [q_data_half fliplr(q_data_half(1:end-1))];
  endif
  