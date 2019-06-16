import math

'''
aashutosh001
'''

MOD = 1000000007


def modInverse(a, MOD):
    g = gcd(a, MOD)
    return power(a, MOD - 2, MOD)


def power(x, y, MOD):
    if y == 0:
        return 1

    p = power(x, y // 2, MOD) % MOD
    p = (p * p) % MOD

    if y % 2 == 0:
        return p
    else:
        return ((x * p) % MOD)


def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)


def main():
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        a = k-1
        d = 1-n
        if a%(n-1) == 0:
            terms = a//(n-1)
        else:
            terms = (a-(a%(n-1)))//(n-1) + 1
        sumwa = (2*a + (terms-1)*d)
        sumwa = (sumwa * terms)//2
        print(sumwa%MOD)


if __name__ == '__main__':
    main()
