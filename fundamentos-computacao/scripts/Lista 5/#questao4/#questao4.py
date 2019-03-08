def ContaPalavra(frase,v1,v2):
    for i in range(0,len(frase)):
        achou=False
        for j in range(0,len(v1)):
            if v1[j]==frase[i]:
                v2[j]+=1
                achou=True
        if not achou:
            v1.append(frase[i])
            v2.append(1)
            
arquivo1=open('LETRA.txt','a')
arquivo1.write('\n'+'\nFIM')
arquivo1.close()
arquivo2=open('LETRA.txt','r')
palavras=[]
quantidade=[]
fim=False
while not fim:
    frase=arquivo2.readline()
    frase=frase.upper()
    if len(frase)==0:
        frase=arquivo2.readline()
        frase=frase.upper()
    if frase=="FIM":
        fim=True
    else:
        frase=frase.split()
        ContaPalavra(frase,palavras,quantidade)
        arquivo3=open("PALAVRAS.txt","w")
        for i in range (0,len(palavras)):
            arquivo3.write("Palavra: "+palavras[i]+"   "+"Quantidade: "+\
                          str(quantidade[i])+"\n")
arquivo2.close()
arquivo3.close()
