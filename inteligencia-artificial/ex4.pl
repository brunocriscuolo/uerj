entra_estrada(E):- 
    nl,
    write('Como estao as estradas?'), nl,
    write('(boas, buracos)==>'),
    read(E).

entra_tempo(T) :- 
    nl, 
    write('Como esta o tempo?'), nl,
    write('(sol, chuva)==>'), 
    read(T),nl.

decisao :-
    entra_estrada(Pe), 
    entra_tempo(Pt),
    recomenda_acao(Z,Pe,Pt),
    nl,nl,
    write('Mediante as opções informadas, recomenda-se ==> '), 
    write(Z).

recomenda_acao(C,X,Y) :-
    X=boas, Y=sol -> C='va a praia';
    X=buracos, Y=sol ->  C='va ao parque';
    X=boas, Y=chuva ->  C='va ao restaurante'; 
    X=buracos, Y=chuva ->  C='fique em casa'.

