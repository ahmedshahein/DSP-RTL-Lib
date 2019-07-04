  r_data = 1:11;
  if length(r_data) > 1
    if mod(length(r_data), 2) == 0, % EVEN
      if ( r_data(1:length(r_data)/2) == r_data(length(r_data)/2+1:end) )
        arr_type = "even";
        half_array = r_data(1:length(r_data)/2);
        disp("### INFO: The input array has even symmetry!");
      else
        arr_type = "nosymm";
        half_data = r_data;
        disp("### INFO: The input array has even asymmetry");
      endif
    else
      if ( r_data(1:floor(length(r_data)/2)) == r_data(ceil(length(r_data)/2)+1:end) )
        arr_type = "odd";
        half_array = r_data(1:ceil(length(r_data)/2));
        disp("### INFO: The input array has odd asymmetry!");
      else
        arr_type = "nosymm";
        half_data = r_data;
      endif      
    endif
  endif
