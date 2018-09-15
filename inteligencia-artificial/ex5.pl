pertence(X, [P|R]):- 
    X = P; pertence(X, R).

/* testes: */ 
  pertence(a, [b, c, d, a]). /* verifica se a pertence a lista [b, c, d, a] */
  pertence(ana, [rosa, cravo, violeta]).
 
 
 pertence(E, [a, b, c]). /* lista os elementos da lista */
