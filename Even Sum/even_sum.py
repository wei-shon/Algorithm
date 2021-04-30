for i in range(int(input())):
    even=[]
    num=[int(n) for n in input().split(' ')]
    if num[1]%2==0: 
        num[1]=num[1]+1
    for j in range(num[0],num[1]):
        if j%2==0 :
            even.append(int(j))
    ans=0
    for z in even:
        ans+=z
    print("case "+str(i+1)+": "+str(ans))