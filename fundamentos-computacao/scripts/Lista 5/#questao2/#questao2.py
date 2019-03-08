def ManipulaArquivo(arquivo):
    idades=[]
    salarios=[]
    soma_salario=0
    soma_idade=0
    cont=0
    fim=False
    while not fim:
        linha=arquivo.readline()
        if len(linha)==0:
            linha=arquivo.readline()
        elif linha=='fim':
            fim=True
        else:
            [idade,salario]=linha.split()
            idades.append(idade)
            salarios.append(salario)
    for i in range(0,len(idades)):
        soma_salario+=float(salarios[i])
        soma_idade+=float(idades[i])
        cont+=1
    media_idade=float(soma_idade)/cont
    media_salario=float(soma_salario)/cont
    media=[0]*2
    media[0]=media_idade
    media[1]=media_salario
    return media

media1=[]
file1=open('MAIOR.txt','a')
file1.write("\nfim")
file1.close()
arq1=open('MAIOR.txt','r')
media1=ManipulaArquivo(arq1)
arq1.close()
print "Media de idades em 'MAIOR.txt':", media1[0]
print "Média salarial em 'MAIOR.txt':", media1[1]

media2=[]
file2=open('IDADEM40.txt','a')
file2.write("\nfim")
file2.close()
arq2=open('MAIOR.txt','r')
media2=ManipulaArquivo(arq2)
arq2.close()
print "Media de idades em 'IDADEM40.txt':", media2[0]
print "Média salarial em 'IDADEM40.txt':", media2[1]

media3=[]
file3=open('NOVO.txt','a')
file3.write("\nfim")
file3.close()
arq3=open('NOVO.txt','r')
media3=ManipulaArquivo(arq3)
arq3.close()
print "Media de idades em 'NOVO.txt':", media3[0]
print "Média salarial em 'NOVO.txt':", media3[1]
