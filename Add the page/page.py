n=int(input())
answer=[]
for i in range(n):
    num=int(input())
    page = 0 #to remember what page we lost
    j=0 #the sum of pages
    count=0 #to remember what page we get
    for y in range(1,num+2):#num+2 because if page is 1 then answer is 2,2 but we could not count to 2 so that we should num+2
        if j <= num:
            j+=y
            count+=1
        else:
            break
    page=j-num
    print(count,page)

    