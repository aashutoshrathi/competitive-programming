def plusOne(self, A):
    for i in range(len(A)-1, -1, -1):
        if A[i] == 9:
            A[i] = 0
        else:
            A[i] += 1
            while True:
                if A[0] == 0:
                    del A[0]
                else:
                    return A
            return A

    A = [1] + A
    return A