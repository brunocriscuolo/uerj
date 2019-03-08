def WriteFile(arquivo,time,gols,artilheiro):
    arquivo.write(time+' '+str(gols)+' '+artilheiro+'\n')

def EOF(arquivo):
    arquivo.write('fim')
    arquivo.close()
    
def ManipulaArquivo(arquivo):
    vet_time=[]
    vet_gols=[]
    vet_artilheiro=[]
    vet_dados=[0]*3
    mais_gols=-1
    fim=False
    while not fim:
        linha=arquivo.readline()
        if len(linha)==0:
            linha=arquivo.readline()
        elif linha=='fim':
            fim=True
        else:
            [Time,Gols,Artilheiro]=linha.split()
            vet_time.append(Time)
            vet_gols.append(Gols)
            vet_artilheiro.append(Artilheiro)
    for i in range(0,len(vet_gols)):
        if vet_gols[i]>mais_gols:
            mais_gols=vet_gols[i]
            vet_dados[0]=vet_time[i]
            vet_dados[1]=mais_gols
            vet_dados[2]=vet_artilheiro[i]
    return vet_dados
                           

arq1=open('DADOS.txt','w')
time=raw_input("Time:")
while time!='x' and time!='X':
    gols=input("Quantidade de Gols:")
    artilheiro=raw_input("Artilheiro do Time:")
    WriteFile(arq1,time,gols,artilheiro)
    time=raw_input("Time:")
arq1.close()
arq2=open('DADOS.txt','a')
EOF(arq2)
arq3=open('DADOS.txt','r')
dados=[]
dados=ManipulaArquivo(arq3)
print "Time que fez mais gols:", dados[0]
print "Quantidade de gols do time:", dados[1]
print "Artilheiro do time:", dados[2]
    
    
