arr = [1]
for i in range(4, 17, 2):
    arr.append(2 - arr[-1] + 2*pow(3, (i-1)//2))
print(arr)
