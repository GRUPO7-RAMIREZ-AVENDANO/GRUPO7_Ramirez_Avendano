final=int(input("Ingrese número: "))
sum=0
output="1"
for i in range(1,(final+1)):
    sum=sum+i
    if i > 1:
        output=output+"+"+str(i)
print(output+"="+str(sum))
