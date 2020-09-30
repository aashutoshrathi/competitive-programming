'''
FooBar Level 2
Problem 1
Solved in 10hrs (includes day at work)
'''

FIRST_BENCHER_MOVES = [10, -6, 17, -15]
LAST_BENCHER_MOVES = [-1*i for i in FIRST_BENCHER_MOVES]
SECOND_BENCHER_MOVES = [15, 17, 10, -6]
SECOND_LAST_BENCHER_MOVES = [-1*i for i in SECOND_BENCHER_MOVES]


def get_allowed_moves(top):
    if top % 8 == 0:
        return FIRST_BENCHER_MOVES
    elif top % 8 == 7:
        return LAST_BENCHER_MOVES
    elif top % 8 == 1:
        return SECOND_BENCHER_MOVES
    elif top % 8 == 6:
        return SECOND_LAST_BENCHER_MOVES
    else:
        return FIRST_BENCHER_MOVES + LAST_BENCHER_MOVES


def in_limits(base, num):
    if num//8 == base//8:
        return False
    return num >= 0 and num <= 63


def solution(src, dest):
    tracker = list(bytearray(64))  # initialize by all zeroes
    q = []
    steps = 10**100
    q.append([src, 0])
    while len(q):
        curr = q.pop(0)
        # print(curr)
        top = curr[0]
        t_moves = curr[1]
        tracker[top] = 1
        if top == dest:
            steps = min(t_moves, steps)
            if steps < 2:
                break
        allowed_moves = get_allowed_moves(top)
        # print(top, allowed_moves)
        t_moves += 1
        if t_moves < steps:
            for i in allowed_moves:
                if in_limits(top, top+i) and tracker[top+i] == 0:
                    # print(top, '->', (top+i), 'q.size: ', len(q))
                    q.append([top+i, t_moves])

    return steps


if __name__ == "__main__":
    a, b = map(int, input().split())
    print(solution(a, b))
