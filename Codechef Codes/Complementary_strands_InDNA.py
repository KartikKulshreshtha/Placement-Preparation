t = int(input())
for _ in range(t):
    n = int(input())
    String = input()
    string1 = ''
    for i in String:
        if i == "A":
            string1 += "T"
        elif i == "T":
            string1 += "A"
        elif i == "C":
            string1 += "G"
        elif i == "G":
            string1 += "C"
    print(string1)