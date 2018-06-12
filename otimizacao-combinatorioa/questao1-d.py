from cvxpy import *
import time

#Inicio da execução
inicio=time.time()

#Declarando as variáveis de otimização
y1=Variable()
y2=Variable()
y3=Variable()

#Descreve a função objetivo na forma DUAL
objective=Minimize(240000*y1+180000*y2+110000*y3)

#Lista as restrições do problema
constraints=[y1+1.5*y2+y3<=0.56,2*y1+y2+0*y3<=0.42,y1>=0,y2>=0,y3>=0]

#Função de formulação do problema de otimização
prob=Problem(objective,constraints)

#Retorna o valor ótimo
prob.solve()
print "Optimal (y1+1.5*y2+y3<=0.56) dual variable:", constraints[0].dual_value
print "Optimal (2*y1+y2<=0.42) dual variable:", constraints[1].dual_value

#fim execução
fim=time.time()
print " Tempo de Execução:", fim-inicio,"s"
