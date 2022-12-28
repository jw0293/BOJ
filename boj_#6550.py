import sys
import collections

def solution(text, hint):
    idx = 0
    for i in range(len(hint)):
        if hint[i] == text[idx]:
            idx += 1
            if idx == len(text):
                return 'Yes'
    return 'No'

while True:
    try:
        text, hint = input().split()
        answer = solution(text, hint)
        print(answer)
    except:
        break