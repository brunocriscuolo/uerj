/* Somar todos os elementos de uma lista */

soma([], 0).
soma([H|T], S):-
    soma(T,G), S is H+G.


/* Quantidade de elementos de uma lista */

qtde([],0).
qtde([_|T], S):-
    qtde(T,G), S is 1+G.

/* Media Aritmetica de unma lista */ 

mediaarit(L, M):- 
    soma(L,S), qtde(L,T),
    M is S/T. 



/* Consultas: 
soma([2,3,4], S).
qtde([2,3,4], S).
mediaarit([2,3,4,5], M).
*/

