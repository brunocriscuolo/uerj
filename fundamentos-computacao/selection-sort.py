
def SelectionSort(vetor):
    for i in range(0,len(vetor)-1):
        menor=i
        for j in range(i+1,len(vetor)):
            if vetor[menor]>vetor[j]:
                menor=j
        aux=vetor[i]
        vetor[i]=vetor[menor]
        vetor[menor]=aux
    return vetor

import random
tam=random.randint(5,10)
vet=[0]*tam
for i in range (0,tam):
    vet[i]=random.randint(1,100)
random.shuffle(vet)
print vet    
vet_ord=[]
vet_ord=SelectionSort(vet)
print "\nVetor Ordenado:", vet_ord
