n = int(input())
p = [0]*(n+1)
x = 0
for i in range(2, n+1):
    if p[i] == 0:
        x += 1
        p[i] = x
        for j in range(i, n+1, i):
            p[j] = p[i]
    print(p[i], end=' ')
print()