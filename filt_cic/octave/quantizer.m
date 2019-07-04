function QLevels = quantizer(Q, QType, DType)
% QLevels = quantizer(Q, QType, DType)
% INPUT PARAMETERS:-
% Q: Quantizer bit-width
% QType: Select quantizer type either "midriser" or "midtread"
% DType: Data Type either "signed" or "unsigned"
%
% midtread has 0 value
% OUTPUT DATA:-
% QLevels: Array of size 2^Q
  nol = 2^Q;
  if (strcmp(QType,"midtread"))
    for (i = 1:nol),
      j = i-1;
      if strcmp(DType, "signed")
        quantizer_levels(i) = ((2.0*j) - nol)/nol;      
      else
        quantizer_levels(i) = j/nol;
    endif
    endfor
  else
    for i = 1 : nol,
      j = i-1;
      if strcmp(DType, "signed")
	      quantizer_levels(i) = (((2.0*j) + 1.0) - nol)/nol;
      else
        quantizer_levels(i) = (j + 1.0)/nol;
      endif
    endfor
  endif
  
  QLevels = quantizer_levels;
% EOF