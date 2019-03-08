def WriteFile(file_name,age,name):
    file_name.write(name+' '+str(age)+'\n')

def EOF(file_name):
    file_name.write('fim')
    file_name.close()
    
def BuscaBinaria(vetor,elemento):
    vetor.sort()
    inicio=0
    fim=len(vetor)-1
    achou=False
    while inicio<=fim and not achou:
        meio=(inicio+fim)//2
        if elemento==vetor[meio]:
            achou=True
        elif elemento<vetor[meio]:
            fim=meio-1
        else:
            inicio=meio+1
    return achou

arquivo1=open('DADOS.txt','w')
idade=input("Idade: ")
while idade>0:
    nome=raw_input("Nome: ")
    WriteFile(arquivo1,idade,nome)
    idade=input("Idade: ")
arquivo1.close()
arquivo2=open('DADOS.txt','a')
EOF(arquivo2)
nomes=[]
idades=[]
arquivo3=open('DADOS.txt','r')
fim=False
while not fim:
    linha=arquivo3.readline()
    if len(linha)==0:
        linha=arquivo3.readline()
    elif linha=='fim':
        fim=True
    else:
        linha=linha.split()
        for i in range(0,len(linha)):
            if linha[i].isalpha():
                nomes.append(linha[i])
            else:
                idades.append(linha[i])
elem=raw_input("Nome procurado: ")
achou=BuscaBinaria(nomes,elem)
if achou:
    print "Nome:", elem
    for i in range(0,len(nomes)):
        if elem==nomes[i]:
            print "Idade:",idades[i]
else:
    print "Nome não encontrado."
