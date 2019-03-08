def LerMatriz(m):
    m=[]
    for i in range(0,7):
        m.append(0)
        m[i]=[]
        for j in range(0,7):
            m[i].append(input("Número:"))
    return m

def SomaLinha6(m):
    somaLinha=0
    for j in range(0,7):
        somaLinha+=m[5][j]
    return somaLinha

def SomaColuna2(m):
    somaColuna=0
    for i in range(0,7):
        somaColuna+=m[i][1]
    return somaColuna

def SomaDiagonal(m):
    somaDiagonal=0
    for i in range(0,7):
        somaDiagonal+=m[i][i]
    return somaDiagonal

def SomaPar(m):
    somaPar=0
    for i in range(0,7):
        for j in range(0,7):
            if m[i][j]%2==0:
                somaPar+=m[i][j]
    return somaPar

def PrintElem(m):
    return m[2][3]

mat=[]
mat=LerMatriz(mat)
print "\nMATRIZ:"
for i in range(0,7):
    for j in range(0,7):
        
        print "%2d"% mat[i][j],
    print

print "\nSoma dos Elemenots da Linha 06:", SomaLinha6(mat)
print "Soma dos Elementos da Coluna 02:", SomaColuna2(mat)
print "Soma dos Elementos da Diagonal Principal:", SomaDiagonal(mat)
print "Elemento da Linha 03 e Coluna 04:", PrintElem(mat)
print "Soma dos Elementos Pares da Matriz:", SomaPar(mat)
