progenitor(maria, jose). 
progenitor(joao, jose).
progenitor(joao, ana).
progenitor(jose, julia).
progenitor(jose, iris).
progenitor(iris, jorge).

masculino(joao).
masculino(jose).
masculino(jorge).

feminino(maria).
feminino(ana).
feminino(iris).
feminino(julia).

filho(X,Y):-progenitor(Y,X).
mae(X,Y):-progenitor(X,Y), feminino(X).
pai(X,Y):-progenitor(X,Y), masculino(X).
avo(X,Z):-pai(X,Y), progenitor(Y,Z).
avoh(X,Z):-mae(X,Y), progenitor(Y,Z).
irma(X,Y):-progenitor(Z,Y), progenitor(Z,X), feminino(X), X\=Y.
irmao(X,Y):-progenitor(Z,Y), progenitor(Z,X), masculino(X), X\=Y.
tia(X,Y):-progenitor(Z,Y), irma(X,Z).
antepassado(X,Z):-progenitor(X,Z).
antepassado(X,Z):-progenitor(X,Y), antepassado(Y,Z).
