import sys
import collections

gather = ['a', 'e', 'i', 'o', 'u']

def isValidGather(pw):
    includeGather = False
    for ch in pw:
        if ch in gather:
            includeGather = True
            break
    return includeGather

def isValidSequenceGrammer(pw):
    gatherCnt = 0
    consonant = 0
    for ch in pw:
        if ch in gather:
            consonant = 0
            gatherCnt += 1
            if gatherCnt == 3:
                return False
        else:
            gatherCnt = 0
            consonant += 1
            if consonant == 3:
                return False
    return True

def isValidSameChar(pw):
    for i in range(len(pw)):
        if i == 0:
            continue
        if pw[i] == pw[i-1]:
            if pw[i] == 'e' or pw[i] == 'o':
                continue
            else:
                return False
    return True

def solution(pw):
    includeGather = isValidGather(pw)
    if includeGather == False:
        return False
    
    sequenceSameChar = isValidSequenceGrammer(pw)
    if sequenceSameChar == False:
        return False

    sameChar = isValidSameChar(pw)
    if sameChar == False:
        return False
    return True
    

while True:
    pw = input()
    if pw == 'end':
        break
    answer = solution(pw)
    if answer == True:
        print(f'<{pw}> is acceptable.')
    else:
        print(f'<{pw}> is not acceptable.')