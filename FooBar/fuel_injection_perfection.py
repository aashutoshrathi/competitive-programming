'''
Fuel Injection Perfection
=========================

Commander Lambda has asked for your help to refine the automatic quantum 
antimatter fuel injection system for her LAMBCHOP doomsday device. 
It's a great chance for you to get a closer look at the LAMBCHOP - 
and maybe sneak in a bit of sabotage while you're at it - so you took the job gladly. 

Quantum antimatter fuel comes in small pellets, 
which is convenient since the many moving parts of 
the LAMBCHOP each need to be fed fuel one pellet at a time. 
However, minions dump pellets in bulk into the fuel intake. 
You need to figure out the most efficient way to sort and shift the 
pellets down to a single pellet at a time. 

The fuel control mechanisms have three operations: 

1) Add one fuel pellet
2) Remove one fuel pellet
3) Divide the entire group of fuel pellets by 2 (due to the destructive 
energy released when a quantum antimatter pellet is cut in half, 
the safety controls will only allow this to happen if there is an even number of pellets)

Write a function called solution(n) which takes a positive integer as a string 
and returns the minimum number of operations needed to transform 
the number of pellets to 1. 
The fuel intake control panel can only display a number up to 309 digits long,
so there won't ever be more pellets than you can express in that many digits.

For example:
solution(4) returns 2: 4 -> 2 -> 1
solution(15) returns 5: 15 -> 16 -> 8 -> 4 -> 2 -> 1

Test cases
==========
Your code should pass the following test cases.
Note that it may also be run against hidden test cases not shown here.

-- Test cases --
Input:
solution.solution('15')
Output:
    5

Input:
solution.solution('4')
Output:
    2
'''
def solution(n):
    ans = 0
    n = int(n)
    while n > 1:
        # print(n)
        # Simple even case ..10, ..00
        # 3) Divide the entire group of fuel pellets by 2
        if n % 2 == 0:
            n //= 2

        # 3 & ..01 case
        # 2) Remove one fuel pellet
        elif n == 3 or n % 4 == 1:
            # print(n)
            n = n - 1

        # All ending with 11 except 3
        # 1) Add one fuel pellet
        else:
            # print(n)
            n = n + 1

        ans += 1

    return ans


if __name__ == "__main__":
    n = input()
    print(solution(n))
