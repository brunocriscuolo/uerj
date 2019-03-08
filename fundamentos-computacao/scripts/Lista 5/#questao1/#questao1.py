def WriteFile(file_name,age,pay):
    file_name.write("Idade: "+str(age)+'\n'+\
                   "Salário: "+str(pay)+'\n'+'\n')

arq1=open('MAIOR.txt','w')
arq2=open('IDADEM40.txt','w')
arq3=open('NOVO.txt','w')
idade=input("Idade do funcionário: ")
while idade>0:
    salario=input("Salário do funcionário: ")
    if salario>3000:
        WriteFile(arq1,idade,salario)
    elif idade>40:
        WriteFile(arq2,idade,salario)
    else:
        WriteFile(arq3,idade,salario)
    idade=input("Idade do funcionário: ")
arq1.close()
arq2.close()
arq3.close()

    
