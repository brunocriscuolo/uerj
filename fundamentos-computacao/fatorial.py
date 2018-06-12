n = input("Digite um número: ")
fat = 1
aux = n
while n>0:
    fat = fat*n
    n = n-1
print "Fatorial de", aux, "é", fat
