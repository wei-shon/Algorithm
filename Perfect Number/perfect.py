n=int(input())
answer=[]
num=[int(y) for y in input().split(' ')]
for i in range(n):
    factor=[]
    total=0 #use to calculate the sum of factors
    for j in range(1,num[i]):
        if num[i]%j==0:
            factor.append(int(j))
    for y in factor:
        total+=y
    if total==num[i]:
        answer.append(int(num[i]))
for z in range(len(answer)):
    if z==len(answer)-1:
        print(answer[z],end='')
    else:
        print(answer[z],end=' ')