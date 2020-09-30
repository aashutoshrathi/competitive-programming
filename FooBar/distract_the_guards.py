'''
Distract the Guards
===================

The time for the mass escape has come, and you need to distract the guards so
that the bunny prisoners can make it out! Unfortunately for you, they're
watching the bunnies closely. Fortunately, this means they haven't realized yet
that the space station is about to explode due to the destruction of the
LAMBCHOP doomsday device. Also fortunately, all that time you spent working as
first a minion and then a henchman means that you know the guards are fond of
bananas. And gambling. And thumb wrestling.

The guards, being bored, readily accept your suggestion to play the Banana
Games.

You will set up simultaneous thumb wrestling matches. In each match, two guards
will pair off to thumb wrestle. The guard with fewer bananas will bet all their
bananas, and the other guard will match the bet. The winner will receive all of
the bet bananas. You don't pair off guards with the same number of bananas (you
will see why, shortly). You know enough guard psychology to know that the one
who has more bananas always gets over-confident and loses. Once a match begins,
the pair of guards will continue to thumb wrestle and exchange bananas, until
both of them have the same number of bananas. Once that happens, both of them
will lose interest and go back to guarding the prisoners, and you don't want
THAT to happen!

For example, if the two guards that were paired started with 3 and 5 bananas,
after the first round of thumb wrestling they will have 6 and 2 (the one with 3
bananas wins and gets 3 bananas from the loser). After the second round, they
will have 4 and 4 (the one with 6 bananas loses 2 bananas). At that point they
stop and get back to guarding.

How is all this useful to distract the guards? Notice that if the guards had
started with 1 and 4 bananas, then they keep thumb wrestling! 1, 4 -> 2, 3 -> 4,
1 -> 3, 2 -> 1, 4 and so on.

Now your plan is clear. You must pair up the guards in such a way that the
maximum number of guards go into an infinite thumb wrestling loop!

Write a function solution(banana_list) which, given a list of positive integers
depicting the amount of bananas the each guard starts with, returns the fewest
possible number of guards that will be left to watch the prisoners. Element i of
the list will be the number of bananas that guard i (counting from 0) starts
with.

The number of guards will be at least 1 and not more than 100, and the number of
bananas each guard starts with will be a positive integer no more than
1073741823 (i.e. 2^30 -1). Some of them stockpile a LOT of bananas.

Languages
=========

To provide a Python solution, edit solution.py To provide a Java solution, edit
Solution.java

Test cases
==========
Your code should pass the following test cases. Note that it may also be run
against hidden test cases not shown here.

-- Python cases -- Input: solution.solution(1,1) Output: 2

Input: solution.solution([1, 7, 3, 21, 13, 19]) Output: 0

-- Java cases -- Input: solution.solution(1,1) Output: 2

Input: Solution.solution([1, 7, 3, 21, 13, 19]) Output: 0

Use verify [file] to test your solution and see how it does. When you are
finished editing your code, use submit [file] to submit your answer. If your
solution passes the test cases, it will be removed from your home folder.
'''

from fractions import gcd


def infinite_loop(guard_one, guard_two):
    '''
    returns if guards go in infinite bets
    '''
    val = (guard_one+guard_two)//gcd(guard_one, guard_two)
    return val & (val - 1)


def solution(banana):
    '''
    returns min number of guards that will be free
    Takes bananas as input array
    '''
    leng = len(banana)
    graph = {i: [] for i in range(leng)}
    to_iterate = list(range(leng))

    def connect():
        # Connect Guards who can play infinte games
        for i in range(leng-1):
            for j in range(i+1, leng):
                if infinite_loop(banana[i], banana[j]):
                    graph[i].append(j)
                    graph[j].append(i)

    def connection_add_remove(t_set, ways, i, add):
        if add:
            t_set.add((ways[i], ways[i+1]))
            t_set.add((ways[i+1], ways[i]))
        else:
            t_set.remove((ways[i], ways[i+1]))
            t_set.remove((ways[i+1], ways[i]))

    def hopcroft_karp():
        has_way = True
        while has_way:
            has_way = False
            for itr in to_iterate:
                flag = False
                curr = itr
                marked = set()
                ways = list()

                while True:
                    marked.add(curr)

                    for guard in graph.get(curr, []):
                        if guard in marked:
                            continue
                        if (not flag and (curr, guard) in part) or (flag and (curr, guard) in matches):
                            ways.append(curr)
                            ways.append(guard)
                            break

                    if not ways:
                        break

                    if ways[-1] != itr and ways[-1] in to_iterate:
                        has_way = True
                        for i in range(len(ways) - 1):
                            condition = (ways[i], ways[i + 1]) in matches
                            connection_add_remove(
                                matches, ways, i, not condition)
                            connection_add_remove(
                                part, ways, i, condition)

                        to_iterate.remove(ways[0])
                        to_iterate.remove(ways[-1])
                        break

                    curr = ways.pop()
                    flag = not flag

        return len(to_iterate)

    connect()

    part = set([(i, j) for i in graph for j in graph[i]])
    matches = set()

    return hopcroft_karp()
