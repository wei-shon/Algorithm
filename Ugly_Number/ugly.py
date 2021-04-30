n=int(input())
for i in range(n):
    answer=0
    num=int(input())
    if num==1:
        print(1)
        continue
    num=num-1 #since 1 is also ugly number, we should count from 2 so taht we sub 1 
    run=2
    while num!=0:
        count = run #use count to calculate because we need 'run' to continue count so we cannot lost this number 
        while True:
            if count%2==0:
                count=count//2
            elif count%3==0:
                count=count//3
            elif count%5==0:
                count=count//5
            elif count==1:
                num-=1
                run+=1
                break
            else:
                run+=1
                break
        answer=run-1
    print(answer)
