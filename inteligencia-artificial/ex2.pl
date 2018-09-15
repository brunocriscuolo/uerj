ave(piupiu).
peixe(sereia).
minhoca(irgh).
gostar(ave, minhoca).
gostar(ave, peixe).
gostar(gato, ave).
gostar(gato, peixe).
gostar(X,Y):- amigo(X,Y).
amigo(gato, eu).
come(X,Y):-gostar(X,Y).

%?gostar(X,Y).
%?amigo(X,Y).
%?come(X,Y).
