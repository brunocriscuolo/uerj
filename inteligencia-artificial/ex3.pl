ave(piupiu).
peixe(sereia).
minhoca(irgh).
gato(meugato).
amigo(meugato, eu).
gosta(X,Y):-(ave(X), minhoca(Y); (gato(X), peixe(Y); ave(Y))); amigo(X,Y).
come(X,Y):- gosta(X,Y).
