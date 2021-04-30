num=[]
n=int(input())
for i in range(1,n+1):
    num.append(int(input()))
    num=sorted(num)
    if i%2!=0:
        number=i//2+1
        number-=1
        print(num[number])
    else:
        number1=num[int(i//2-1)]
        number2=num[int(i//2)]
        ans=(number1+number2)//2
        print(ans)