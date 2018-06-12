n=input("Quantiddae de termos da PA:")
a1=input("Primeiro termo da PA:")
r=input("Razão da PA:")
aux=n+1
s=0
for i in range(1,aux):
    t=a1+(i-1)*r
    s=s+t
    print t
print "Soma dos termos:", s
    
