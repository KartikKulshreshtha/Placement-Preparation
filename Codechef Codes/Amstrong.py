arr = int(input())
num = str(arr)
Sum = 0
for i in range(len(num)):
    x = int(num[i])
    Sum += x * x * x
if Sum == arr:
    print(1)
else:
    print(0)