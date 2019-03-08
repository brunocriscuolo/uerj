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

palavras=[]
quantidade=[]
frase=raw_input("Frase: ")
frase=frase.upper()
frase=frase.split()
ContaPalavra(frase,palavras,quantidade)
arquivo=open("PALAVRAS.txt","w")
for i in range (0,len(palavras)):
    arquivo.write("Palavra: "+palavras[i]+"   "+"Quantidade: "+\
                  str(quantidade[i])+"\n")
arquivo.close()
