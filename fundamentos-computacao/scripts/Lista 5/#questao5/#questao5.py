def Palindromo(cadeia):
    inicio=0
    fim=len(cadeia)-2
    palindromo=True
    while inicio<=fim and palindromo:
        if cadeia[inicio]!=cadeia[fim]:
            palindromo=False
        else:
            inicio+=1
            fim-=1
    return palindromo
            

arquivo1=open('DNA.txt','a')
arquivo1.write('\n'+'\nfim')
arquivo1.close()
arquivo2=open('DNA.txt','r')
fim=False
pal=[]
while not fim:
    linha=arquivo2.readline()
    linha=str(linha)
    if linha=='fim':
        fim=True
    palindromo=Palindromo(linha)
    if palindromo:
        pal.append(linha)
arquivo3=open('PALINDROMOS.txt','w')
for i in range(0,len(pal)):
    arquivo3.write(str(pal[i])+'\n')
arquivo2.close()
arquivo3.close()
