def BuscaBinaria(vetor,elemento):
    inicio=0
    fim=len(vetor)-1
    posicao=0
    achou=False
    while inicio<=fim and not achou:
        meio=(inicio+fim)//2
        if elemento==vetor[meio]:
            achou=True
            posicao=meio
        elif elemento<vetor[meio]:
            fim=meio-1
        else:
            inicio=meio+1
    return posicao
    

import random
tam=random.randint(5,10)
vet=[0]*tam
for i in range (0,tam):
    vet[i]=random.randint(1,100)
random.shuffle(vet)
print vet    
vet.sort()
print "\nVetor Ordenado:", vet
x=input("\nElemento Procurado:")
busca=BuscaBinaria(vet,x)
if busca==0:
    print "\nO elemento procurado não pertencente ao vetor."
else:
    print "\nO elemento",x,"foi encontrado na posição",busca



