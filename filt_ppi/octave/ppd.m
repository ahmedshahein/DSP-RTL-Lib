  clear
  clc
  
  D = 4;
  %x = [-120, -50, -127, -3, -77, -39, -1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1];%cw
     % Test-Case-02
  %x =[0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]; 
  
  %x = [5,5,5,5,5,15,25,35,-3,-127,-50,-120,0,-1,-39,-77,0,0,1,0,1,1,1,0,1,1,1,1];%ccw
  %x =[5,5,5,5,35,-120,-77,-127,-39,-1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0];
  %% CCW
  % Test-Case-01
%  x =[5,5,5,5,...
%     -127,-77,-120,35,...
%     0,0,-1,-39,...
%     0,0,0,0,...
%     0,0,1,0,...
%     0,0,0,0,...
%     0,0,0,0];
   % Test-Case-02
  x =[1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1];    
  %b = [5,10,15,20,25,30,25,20,15,10,5];
  b = [    0;
    -2;
     6;
   -17;
    37;
   -64;
    95;
  -119;
   127;
  -119;
    95;
   -64;
    37;
   -17;
     6;
    -2;
     0 ]; b=b';
  %y = decimate(x, 4, 7, "fir");
  %
  %yy= filter(b,1,downsample(x,4,0))
  %yy= downsample(filter(b,1,x),D,0);
  
  col = ceil(length(b)/D);
  row = D;
  
  if (col*row > length(b)),
    b = [b zeros(1,col*row-length(b))];
  end
  
  ppd_matrix = zeros(row, col);
  for i = 1 : col,
    for j = 1 : row,
      ppd_matrix(j,i) = b(row*(i-1)+j);  %b(row*i+j)
    end
  end
  
  tf=1;
  ppd_commutator = zeros(row, ceil(length(x)/D));
  if tf
    for i = 1 : size(ppd_commutator,2)
      ppd_commutator(:,i) = x((i-1)*row+1:row*i)';
    end
  else
    for i = 1 : size(ppd_commutator,2),
      if i == 1,
        ppd_commutator(:,i) = x((i-1)*row+1:row*i)';
      else
        ppd_commutator(:,2:end) = ppd_commutator(:,1:end-1);
        ppd_commutator(:,1) = x((i-1)*row+1:row*(i-1)+row)';
      end
    end
  end
  
  k=1;
  for i = 1 : size(ppd_commutator,2)
    for j = 1 : size(ppd_matrix,2)
      mul(:,k) = ppd_matrix(:,j) .* ppd_commutator(:,i);
      k=k+1;
    end
  end
  
  sum(mul)
