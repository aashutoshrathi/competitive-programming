import re


def search(pat, txt):
    M = len(pat)
    N = len(txt)
    lps = [0]*M
    j, count = 0, 0
    cla(pat, M, lps)
    i = 0
    while i < N:
        if pat[j] == txt[i]:
            i += 1
            j += 1
        if j == M:
            count += 1
            j = lps[j-1]
        elif i < N and pat[j] != txt[i]:
            if j != 0:
                j = lps[j-1]
            else:
                i += 1
    return count


def cla(pat, M, lps):
    ll = 0
    lps[0]
    i = 1
    while i < M:
        if pat[i] == pat[ll]:
            ll += 1
            lps[i] = ll
            i += 1
        else:
            if ll != 0:
                ll = lps[ll-1]
            else:
                lps[i] = 0
                i += 1


def getAllSubstr(s, n):
    res = []
    for i in range(n):
        temp = ""
        for j in range(i, n):
            temp += s[j]
            res.append(temp)
    res.append("")
    return res


def cnt(string, sub_string):
    len1 = len(string)
    len2 = len(sub_string)
    j = 0
    counter = 0
    while(j < len1):
        if(string[j] == sub_string[0]):
            if(string[j:j+len2] == sub_string):
                counter += 1
        j += 1

    return counter


def main():
    t = int(input())
    while t > 0:
        a = input()
        b = input()
        n = int(input())
        m = dict()

        for _ in range(n):
            s, beauty = input().split()
            beauty = int(beauty)
            m[s] = beauty

        a_res = getAllSubstr(a, len(a))

        b_res = getAllSubstr(b, len(b))

        maxBeauty = 0
        # ese_hi = dict()

        for i in a_res:
            for j in b_res:
                tBeauty = 0
                temp = i+j
                for string in m:
                    cnt = search(string, temp)
                    tBeauty += cnt*m[string]

                # ese_hi[temp] = tBeauty
                maxBeauty = max(maxBeauty, tBeauty)

        print(maxBeauty)
        # print(ese_hi)
        t -= 1


if __name__ == "__main__":
    main()
