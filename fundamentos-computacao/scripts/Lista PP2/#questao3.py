soma=0
cont=0
nomes=[]
idades=[]
arquivo1=open('teste1.txt','r')
for linha in arquivo1:
    [nome,idade]=linha.split(' ')
    nomes.append(nome)
    idades.append(idade)
    soma+=int(idade)
    cont+=1
media=float(soma)/cont
arquivo1.close()
arquivo2=open('teste2.txt','w')
for i in range(0,len(nomes)):
    if idades[i]<media:
        arquivo2.write(nomes[i]+'\n')
arquivo2.write("Média de idades:"+" "+str(media)+'\n')
arquivo2.close()

