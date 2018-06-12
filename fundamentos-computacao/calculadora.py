#CALCULADORA BÁSICA

loop="true"
if loop=='false':
    print " "
while loop=="true":
    x = input("Digite um número: ")
    y = input("Digite outro número: ")
    operator = raw_input("Qual operação deseja realizar (+,-,*,/)? ")
    while operator!="+" and operator!="-" and operator!="*" and operator!="/":
      operator=raw_input("Operação INVÁLIDA! Qual operação deseja realizar (+,-,*,/)? ")
    if operator=="+":
        result=x+y
        print x,"+",y,"=",result        
    elif operator=="-":
        result=x-y
        print x,"-",y,"=",result        
    elif operator=="*":
        result=x*y
        print x,"*",y,"=",result      
    elif operator=="/":
        if y==0:
            print "ERRO"
        result=float(x)/float(y)
        print x,"/",y,"=",result
    question=raw_input("Deseja realizar outra operação (sim/não)? ")
    while question!="sim" and question!="não" and question!="nao":
        question=raw_input("Resposta INVÁLIDA!Deseja realizar outra operação (sim/não)? ")
    if question=="nao":
        loop="false"
