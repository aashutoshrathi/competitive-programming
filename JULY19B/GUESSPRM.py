import math

def primeFactors(n):
    v = []
    count = 0;
    while (n % 2) == 0:
        n >>= 1
        count+=1

    if count > 1:
        v.append(2); 
    
    till = math.floor(math.sqrt(n))
    for i in range(3, till, 2):
        count = 0; 
        while n % i == 0: 
            count+=1 
            n = n / i 
        if count>1:
            v.append(i)
  
    if n > 2:
        v.append(n)
    return v

def main():
    t = int(input())
    for _ in range(t):
        bada = 999999937
        bahootBada = bada**2
        print("1 " + str(bada))
        x = int(input())
        divisible = bahootBada-x
        pf = primeFactors(divisible)
        for el in pf:
            print("1 " + str(el))
            x = int(input())
            if x == 0:
                print("2 " + str(el))
                s = input()
                break


if __name__ == "__main__":
    main()