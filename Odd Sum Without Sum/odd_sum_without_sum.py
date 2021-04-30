for i in range(int(input())):
    odd=[]
    num=[int(n) for n in input().split(' ')]
    if num[1]%2!=0: 
        num[1]=num[1]+1
    for i in range(num[0],num[1]):
        if i%2!=0 :
            odd.append(int(i))
    m=-1
    ans=0
    for z in odd:
        m+=1
        for j in range(2,z):
            if z%j==0:
                ans+=z
                break
    print(ans)
            # elif j==z-1:
            #     odd[m]=odd[m]+1
    # for i in odd:
    #     if i%2!=0:
    #         ans+=i
    # print(ans)