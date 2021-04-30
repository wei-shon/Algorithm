n=int(input())
num=[]
power=0
i=2
print(str(n)+'=',end='')
# find out pirme factor and its power
while (i <= n) :
    if n%i==0: 
        power+=1
        n=n/i
        if n==1:
            num.append(int(i))
            num.append(int(power))
    else:
        num.append(int(i))
        num.append(int(power))
        power=0
        i+=1
# print out the result
for i in range(0,len(num)):
    if i==len(num)-1:
        if num[i]>0:
            if num[i]==1:
                print(str(num[i-1]))
            else:
                print(str(num[i-1])+'^'+str(num[i]))
    elif i%2==1 and num[i] > 0:
        if num[i]==1:
            print(str(num[i-1])+'*',end='')
        else:
            print(str(num[i-1])+'^'+str(num[i])+'*',end='')
