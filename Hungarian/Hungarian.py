from itertools import permutations
temp = [int(n) for n in input().split(' ')]
name = temp[0]
event = temp[1]
total=[]
for n in range(name):
    EventDetail=[int(n) for n in input().split(' ')]
    total.append(EventDetail)
    EventDetail=[]
totalscore = 0
for p in permutations(range(event),name):
    temp = 0
    j = 0 
    for i in p: 
        temp+=total[j][i]
        j+=1
    if temp>totalscore:
        totalscore=temp
print(totalscore)