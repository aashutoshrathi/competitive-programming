# Amazon
# https://www.interviewbit.com/problems/excel-column-title/

def convertToTitle(A):
    res = ''
    while A>0:
        res += 'Z' if A%26 == 0 else chr(64+A%26)
        A = A//26 - (A%26 == 0)
    return res[::-1]