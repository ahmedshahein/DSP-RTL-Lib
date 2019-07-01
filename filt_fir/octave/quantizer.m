function QLevels = quantizer(Q, QType)
% QLevels = quantizer(Q, QType)
% INPUT PARAMETERS:-
% Q: Quantizer bit-width
% QType: Select quantizer type either "midriser" or "midtread"
%
% OUTPUT DATA:-
% QLevels: Array of size 2^Q

  nol = 2^Q;
  if (strcmp(QType,"midtread"))
    for (i = 1:nol),
      j = i-1;
      quantizer_levels(i) = ((2.0*j) - nol)/nol;      
    endfor
  else
    for i = 1 : nol,
      j = i-1;
	    quantizer_levels(i) = (((2.0*j) + 1.0) - nol)/nol;
    endfor
  end
  
  QLevels = quantizer_levels;
% EOF