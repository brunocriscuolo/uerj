        
def ler_matriz():
    mat=[]
    for i in range(0,3):
        mat.append(0)
        mat[i]=[]
        for j in range(0,3):
            mat[i].append(int(input("Digite um número:")))
    return mat

def matriz_vazia():
    mat=[]
    for i in range(0,3):
        mat.append(0)
        mat[i]=[]
        for j in range(0,3):
            mat[i].append(0)
    return mat


def coluna1(mat1,mat2):
    for i in range (0,3):
        mat2[i][0]=mat1[i][0]*2
    return mat2

def coluna2(mat1,mat2):
    vet=[]
    for i in range (0,3):
        vet[i]=mat1[i][1]
    col_ord=ordenacao(vet)
    for i in range(0,3):
            mat2[i][1]=col_ord[i]
    return mat2

def ordenacao(vet):
    vet=[]
    for i in range (0,len(vet)-1):
        for j in range (i+1,len(vet)):
            if vet[i]>vet[j]:
                aux=vet[i]
                vet[i]=vet[j]
                vet[j]=aux
    return vet

def coluna3(mat1,mat2):
    for i in range (0,3):
        fat=fatorial(mat1[i][2])
        mat2[i][2]=fat
    return mat2

def fatorial(num):
    fat = 1
    for i in range (0,num):
        fat*=n
        n-=1
    return fat

mat1=ler_matriz()
mat2=matriz_vazia()
mat2=coluna1(mat1,mat2)
mat2=coluna2(mat1,mat2)
mat2=coluna3(mat1,mat2)
        


    
