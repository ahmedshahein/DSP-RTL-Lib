function save2file(filename, data)
  
  fid = fopen(filename, 'w');
  for i = 1 : length(data),
    fprintf(fid, '%d\n', data(i));
  end
  fclose(fid);