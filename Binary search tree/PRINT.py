from itertools import combinations
n = int(input())
x = int(input())
List = []
for i in range(1, n+1):
    List.append(i)
perms = combinations(List, x)
for i in list(perms):
    print(list(i))