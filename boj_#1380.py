import collections

senario = 1

while(True):
    n = int(input())
    if n == 0:
        break
    names = []
    for i in range(n):
        names.append(input())

    returnNames = collections.defaultdict(int)

    for i in range(2*n-1):
        info = list(input().split())
        returnNames[int(info[0])] += 1

    answerNumber = 0
    for i in range(n):
        if returnNames[i+1] == 1:
            answerNumber = i
            break
    
    print(senario, names[answerNumber])
    senario += 1