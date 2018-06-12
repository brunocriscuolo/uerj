
def BubbleSort(vetor):
    for i in range(0,len(vetor)-1):
        for j in range(i+1,len(vetor)):
            if vetor[i]>vetor[j]:
                aux=vetor[i]
                vetor[i]=vetor[j]
                vetor[j]=aux
    return vetor

import random
tam=random.randint(5,10)
vet=[0]*tam
for i in range (0,tam):
    vet[i]=random.randint(1,100)
random.shuffle(vet)
print vet    
vet_ord=[]
vet_ord=BubbleSort(vet)
print "\nVetor Ordenado:", vet_ord
