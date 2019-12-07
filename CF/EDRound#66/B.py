'''
aashutoshrathi
https://codeforces.com/contest/1175/problem/B
'''

MAX = 4294967295

def main():
    t = int(input())
    x = 0
    stack = []
    for _ in range(t):
        s = input()
        times = 1
        if x > MAX:
            print("OVERFLOW!!!")
            return
        elif len(s)>4:
            curr = int(s[3:])
            stack.append(curr)
        elif s[0] == "e":
            stack.pop()
        elif s[0] == "a":
            for ele in stack:
                times = times * ele
            x += times

    if x > MAX:
        print("OVERFLOW!!!")
    else:
        print(int(x))


if __name__ == '__main__':
    main()
