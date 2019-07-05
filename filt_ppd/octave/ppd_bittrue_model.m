  close all
  clear
  clc
  
  p_decimation_factor = 4;
  p_data_width        = 8;
  p_comm_ccw          = 0;
  p_mul_ccw           = 1;
  p_tf_df             = 1;
  p_coeff_length      = 17;
  p_coeff_width       = 8; 
  p_comm_reg_oup      = 1;
  p_comm_phase        = 1;
  fs  = 1000;
  f   = [0 50 220 fs]/fs;
  b   = remez(p_coeff_length-1, f, [1 1 0 0], [1 1]);
  q_b = quantize(b, p_coeff_width, "midtread", "signed");
  b   = round( (2^(p_coeff_width-1)-1) * q_b);
    
  data = [0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0];
  tmp=data;
        
  row = p_decimation_factor;
  col = ceil(length(b)/p_decimation_factor);
  if (length(b) ~= row*col)
    b = [b zeros(1,row*col-length(b))];
  end
  %% ------------------------------------
  %% CONSTANT MULTIPLIER POLYPHASE MATRIX
  %% ------------------------------------
  ppd_mul = zeros(row, col);
  idx = 1;
  % TRANSPOSED-FORM 
  if (p_tf_df)
    % COUNTER CLOCK-WISE
    if (p_mul_ccw)
      for j = col:-1:1
        for i = row:-1:1
          ppd_mul(i,j) = b(idx);
          idx=idx+1;
        end
      end
    % CLOCK-WISE
    else
      for j = col:-1:1
        for i = 1:row
          ppd_mul(i,j) = b(idx);
          idx=idx+1;
        end
      end
    endif
  % DIRECT-FORM
  else
    % COUNTER CLOCK-WISE
    if (p_mul_ccw)
      for j = 1:col
        for i = row:-1:1
          ppd_mul(i,j) = b(idx);
          idx=idx+1;
        end
      end
    % CLOCK-WISE
    else
      for j = 1:col
        for i = 1:row
          ppd_mul(i,j) = b(idx);
          idx=idx+1;
        end
      end
    endif
  endif
  
  %% ----------------
  %% OFFSET ALIGNMENT
  %% ----------------
  % COMPLEMENTARY ROTATION
  if (p_comm_ccw~=p_mul_ccw)
    data = [zeros(1,p_comm_phase) data];
  % SIMILAR ROTATION
  else
    for (i = 1 : length(data)/p_decimation_factor)
      data( (i-1)*p_decimation_factor+1:i*p_decimation_factor ) = fliplr(data( (i-1)*p_decimation_factor+1:i*p_decimation_factor) );
    end
  endif
  % TRAILER ZERO PADDING
  if (length(data) ~= row*ceil(length(data)/row))
    data = [data zeros(1,row*ceil(length(data)/row)-length(data))];
  end
  
  %% ----------
  %% COMMUTATOR
  %% ----------
  ppd_inp_data = zeros(row,ceil(length(data)/row));
  idx = 1;
  if (p_tf_df)
    if (p_comm_ccw)
      for j = size(ppd_inp_data,2):-1:1
        for i = row:-1:1
          ppd_inp_data(i,j) = data(idx);
          idx=idx+1;
        end
      end
    else
      for j = size(ppd_inp_data,2):-1:1
        for i = 1:row
          ppd_inp_data(i,j) = data(idx);
          idx=idx+1;
        end
      end
    endif
  else
    if (p_comm_ccw)
      for j = 1:size(ppd_inp_data,2)
        for i = row:-1:1
          ppd_inp_data(i,j) = data(idx);
          idx = idx + 1;
        endfor
      endfor
    else    
      
    endif
  endif
  
  
  %% -----------------------
  %% MULTIPLIER + ADDER TREE
  %% -----------------------
  idx=1;
  for x = size(ppd_inp_data,2):-1:1
    ppd_oup_mul(:,:,idx) = ppd_inp_data(:,x) .* ppd_mul;
    ppd_add_tree(:,:,idx) = sum(ppd_oup_mul(:,:,idx));
    idx=idx+1;
  end
  
  for x = 1:size(ppd_inp_data,2)
      if x == 1
        ppd_sum(:,:,x) = ppd_add_tree(:,:,x);
      else
        shift_ppd_sum = [0 ppd_sum(:,1:end-1,x-1)];
        ppd_sum(:,:,x) = ppd_add_tree(:,:,x) + shift_ppd_sum;
      end
  end
  
  for x = 1 : size(ppd_sum,3)
      oup(x) = ppd_sum(:,end,x);
  end
  %%
  % for x = 1:length(data)/p_decimation_factor,
  %     tmp((x-1)*row+1:x*row) = fliplr(data((x-1)*row+1:x*row));
  % end
  %data = [zeros(1,2) data];
  tmp = [tmp zeros(1,length(data)-length(tmp))];
  
  f_data = filter(b,1,tmp);
  d_data = downsample( f_data, ...
                       p_decimation_factor, ...
                       p_decimation_factor-1-p_comm_phase);
  %y=filter(b,1,downsample(data,p_decimation_factor,0));
  
  [oup' d_data']