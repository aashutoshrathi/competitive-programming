n = int(input())
prefix_sum = 0
count_S = 0
answer = 0
a = list(map(int, input().split()))
S = sum(a)

for i in range(1, n):
    prefix_sum += a[i]
    if prefix_sum == 2*S:
        answer += count_S
    if prefix_sum == S:
        count_S += 1

print(answer)
