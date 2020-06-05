'''
Bringing a Gun to a Guard Fight (Given: 15 Days)
===============================

Uh-oh - you've been cornered by one of Commander Lambdas elite guards! Fortunately, 
you grabbed a beam weapon from an abandoned guard post while you were running through 
the station, so you have a chance to fight your way out. But the beam weapon is potentially 
dangerous to you as well as to the elite guard: its beams reflect off walls, meaning you'll have 
to be very careful where you shoot to avoid bouncing a shot toward yourself!

Luckily, the beams can only travel a certain maximum distance before becoming too 
weak to cause damage. You also know that if a beam hits a corner, it will bounce back 
in exactly the same direction. And of course, if the beam hits either you or the guard, 
it will stop immediately (albeit painfully). 

Write a function solution(dimensions, your_position, guard_position, distance) that 
gives an array of 2 integers of the width and height of the room, an array of 2 integers 
of your x and y coordinates in the room, an array of 2 integers of the guard's x and y 
coordinates in the room, and returns an integer of the number of distinct directions that you 
can fire to hit the elite guard, given the maximum distance that the beam can travel.

The room has integer dimensions [1 < x_dim <= 1250, 1 < y_dim <= 1250]. You and the 
elite guard are both positioned on the integer lattice at different distinct positions (x, y) 
inside the room such that [0 < x < x_dim, 0 < y < y_dim]. Finally, the maximum distance 
that the beam can travel before becoming harmless will be given as an 
integer 1 < distance <= 10000.

For example, if you and the elite guard were positioned in a room with dimensions [3, 2],
your_position [1, 1], guard_position [2, 1], and a maximum shot distance of 4, 
you could shoot in seven different directions to hit the elite guard 
(given as vector bearings from your location): 
[1, 0], [1, 2], [1, -2], [3, 2], [3, -2], [-3, 2], and [-3, -2]. 
As specific examples, the shot at bearing [1, 0] is the straight line horizontal 
shot of distance 1, the shot at bearing [-3, -2] bounces off the left wall and then the 
bottom wall before hitting the elite guard with a total shot distance of sqrt(13), 
and the shot at bearing [1, 2] bounces off just the top wall before hitting the 
elite guard with a total shot distance of sqrt(5).


Test cases
==========

Input:
solution.solution([3,2], [1,1], [2,1], 4)
Output:
    7

Input:
solution.solution([300,275], [150,150], [185,100], 500)
Output:
    9
'''

TWO = 2


def sign(a) -> bool:
    '''
    signum function
    '''
    return (a > 0) - (a < 0)


def euclid_distance(src, dst=[0, 0]) -> int:
    '''
    returns euclid_distance of src from dst.
    If dst is not given it is treated as origin
    '''
    return sum([(src[i]-dst[i])**TWO for i in range(TWO)])


def oouch(dim, you, guard, pt) -> bool:
    '''
    returns whether your beams will
    hurt yourself before the guard
    '''
    if pt[0]*pt[1] == 0:  # i.e. one of coordinate is 0
        # and they go opposite
        direction_sum = sum(
            [sign((guard[i]-you[i])*pt[i]) == -1 for i in range(TWO)])
        return direction_sum <= 0
    return False


def slope(pt):
    '''
    return slope of bearing vector
    '''
    if pt[0] == 0:
        return 'inf'
    div = pt[1]/pt[0]
    sym = ''
    if sign(pt[0]) < 1 and sign(pt[1]) < 1:
        sym = 'b'
    elif sign(pt[0]) < 1:
        sym = 'd'
    elif sign(pt[1]) == -1:
        sym = 'n'
    return '{}{}'.format(sym, div)


def reflect(a, b) -> int:
    '''
    returns position of beam after reflection in room
    '''
    res = a % b
    return b - res if (a//b) % TWO else res


def reachable(dim, you, guard, pt) -> bool:
    '''
    returns whether or not beam reaches guard
    '''
    reach = [reflect(pt[i]+you[i], dim[i]) == guard[i] for i in range(TWO)]
    if sum(reach) == TWO:
        return not oouch(dim, you, guard, pt)
    return False


def solution(dim, you, guard, distance):
    d_two = distance**TWO

    if euclid_distance(you, guard) > d_two:
        return 0

    pseudo_valid_pts = []
    for i in range(-dim[0], dim[0]+1):
        if i**TWO <= d_two:
            for j in range(-dim[1], dim[1]+1):
                pt = [i, j]
                if euclid_distance(pt) <= d_two and reachable(dim, you, guard, pt):
                    print(pt)
                    pseudo_valid_pts.append(slope(pt))
    print(set(pseudo_valid_pts))
    return len(set(pseudo_valid_pts))


if __name__ == "__main__":
    dimensions = list(map(int, input().strip().split()))
    your_position = list(map(int, input().strip().split()))
    guard_position = list(map(int, input().strip().split()))
    distance = int(input())
    print(solution(dimensions, your_position, guard_position, distance))
