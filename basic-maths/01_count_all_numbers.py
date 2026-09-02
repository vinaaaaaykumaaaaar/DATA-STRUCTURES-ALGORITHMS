n = input("enter the number")


count = 0

for i in range(0,len(n)):
    count+=1

print(count)



n1 = int(n)

c1 = 0

while(n1>0):
    n1 = n1 // 10
    print(n1)
    c1+=1

print(c1)


    
    