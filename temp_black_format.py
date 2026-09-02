n = input("enter the number to reverse : ")

i = 0 
j = len(n) - 1

while(i<j):
    temp = n[i]
    n[i] = n[j]
    n[j] = temp
    i+=1 
    j-=1


print(n)