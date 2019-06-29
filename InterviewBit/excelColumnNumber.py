# Amazon
# https://www.interviewbit.com/problems/excel-column-number/

def titleToNumber(A):
    res = 0
    i = 0
    for c in reversed(A):
        res = (res + (ord(c)-ord('A')+1))*pow(26, i);
    return res