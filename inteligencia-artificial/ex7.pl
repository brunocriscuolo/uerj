bhaskara(A,B,C,R1,R2) :- 
  	ALFA is sqrt(((B*B)-(4*A*C))),
    R1 is ((-B+ALFA)/(2*A)),
    R2 is ((-B-ALFA)/(2*A)).
