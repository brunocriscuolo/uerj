fatorial(0,1).
fatorial(NUM,FAT):-
    NUM>0,
    PROX is NUM-1, 
    fatorial(PROX,AUX_FAT),
    FAT is NUM * AUX_FAT.
