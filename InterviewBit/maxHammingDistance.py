# https://www.interviewbit.com/problems/sum-of-pairwise-hamming-distance/
# Google 

def hammingDistance(A):
    res = 0
    n = len(A)
    for i in range(0, 32):
        count = 0 
        for j in range(0, n): 
            if ((A[j] & (1 << i))): 
                count += 1 
        res += (count * (n - count) * 2)
    return res%1000000007