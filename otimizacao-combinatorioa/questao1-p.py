from cvxpy import *
import time

#Inicio da execução
inicio=time.time()

#Declarando as duas variáveis de otimização
x1=Variable()
x2=Variable()

#Descreve a função objetivo
objective=Maximize(0.56*x1+0.42*x2)

#Lista as restrições do problema
constraint=[x1+2*x2<=240000,1.5*x1+x2<=180000,x1<=110000,x1>=0,x2>=0]

#Função de formulação do problema de otimização
prob=Problem(objective,constraint)

#Retorna o valor ótimo
result=prob.solve()
print "Status:", prob.status
print "Optimal Value:", prob.value
print "Optimal Variables:"
print " x1 =", x1.value
print " x2 =", x2.value

#fim execução
fim=time.time()
print " Tempo de Execução:", fim-inicio,"s"
