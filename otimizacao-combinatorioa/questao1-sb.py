from cvxpy import *
import time

#Inicio da execução
inicio=time.time()

#Declarando as duas variáveis de otimização
x=Variable()
y=Variable()

#Descreve a função objetivo
objective=Maximize(2*x+y)

#Lista as restrições do problema
constraint=[x+y<=4,x<=3,y<=2,(-1)*x+y<=1,x>=0,y>=0]

#Função de formulação do problema de otimização
prob=Problem(objective,constraint)

#Retorna o valor ótimo
result=prob.solve()
print "Status:", prob.status
print "Optimal Value:", prob.value
print "Optimal Variables:"
print " x =", x.value
print " y =", y.value

#fim execução
fim=time.time()
print " Tempo de Execução:", fim-inicio,"s"
