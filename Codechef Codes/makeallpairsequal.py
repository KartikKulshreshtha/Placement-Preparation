from collections import Counter

t = int(input())
for i in range(t):
    n = int(input())
    List = list(map(int, input().split()))
    count = Counter(List)
    L = []
    for j in sorted(count.values()):
        L.append(j)
    print(n-L[len(L)-1])
        