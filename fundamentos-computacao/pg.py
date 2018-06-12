n=input("Quantiddae de termos da PG:")
a1=input("Primeiro termo da PG:")
q=input("Razão da PG:")
aux=n+1
s=0
for i in range(1,aux):
    t=q**i
    s=s+t
    print t
print "Soma dos termos:", s
