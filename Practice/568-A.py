# aashutoshrathi

def main():
    a, b, c, d = map(int, input().split())
    res = 0
    arr = [a, b, c]
    arr.sort()
    if arr[0] > arr[1]-d:
        res += arr[0]+d-arr[1]
    if arr[2] < arr[1]+d:
        res += d+arr[1]-arr[2]
    print(res)


if __name__ == "__main__":
    main()