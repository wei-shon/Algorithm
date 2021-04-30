n=input()
for i in range(int(n)):
    num=[]
    for n in input().split(' '):
        num.append(int(n))
    times=num[0]
    del num[0]
    m=0
    count=0
    percent=0
    for i in num:
        m+=i
    total=m/times
    for i in num:
        if i>total:
            count+=1
    percent=count/times*100
    print('%.3f' % percent +'%')