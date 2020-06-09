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
from math import atan2, hypot

TWO = 2
GUARD = 42
YOU = 1337
IDS = [YOU, GUARD]
PHASE_CHANGERS = [[1, -1], [-1, -1], [-1, 1]]


def reflect(wall, pt):
    '''
    return reflection of point
    (normally with vertical axes and 0)
    '''
    return (wall - pt) + wall


def solution(dim, you, guard, distance):
    PLAYERS = [you, guard]

    def slope(pt):
        '''
        return slope of bearing vector
        '''
        return atan2(pt[1]-you[1], pt[0]-you[0])

    def euclid_distance(dst):
        '''
        returns euclid_distance of src from dst.
        If dst is not given it is treated as origin
        '''
        return hypot((dst[0]-you[0]), (dst[1]-you[1]))

    def reachable(a):
        '''
        returns whether or not beam reaches guard
        '''
        return distance >= euclid_distance(a) > 0

    def get_in_all_quadrants(bunch):
        '''
        Generates all combinations of 
        point in others 3 quads
        '''
        points = []
        for k in range(len(PHASE_CHANGERS)):
            for j in range(len(bunch)):
                point = [bunch[j][i] * PHASE_CHANGERS[k][i]
                         for i in range(TWO)]
                point.append(bunch[j][2])
                if reachable(point):
                    points.append(point)
        return points

    def get_all_reflections():
        '''
        returns position of beam after reflection in room
        and also multi-roomiverse we created
        '''
        room_replicas = [((you[i] + distance + 1) // dim[i]
                          ) + 1 for i in range(TWO)]

        cx = [[] for _ in range(TWO)]
        cy = [[] for _ in range(TWO)]

        for i in range(0, room_replicas[0]):
            y_list = [[], []]
            curr_x = [you[0], guard[0]]

            # Generate all points parallel to Y Axis
            wall_x = dim[0] * i
            for k in range(TWO):
                if len(cx[k]):
                    curr_x[k] = reflect(wall_x, cx[k][-1][0])
                cx[k].append([curr_x[k], PLAYERS[k][1], IDS[k]])

            # Generate all points parallel to X Axis
            # and mix them well
            for j in range(1, room_replicas[-1]):
                wall_y = dim[1] * j
                curr_y = [0, 0]

                for k in range(TWO):
                    pt = PLAYERS[k][1]
                    if len(y_list[k]):
                        pt = y_list[k][-1]

                    curr_y[k] = reflect(wall_y, pt)
                    y_list[k].append(curr_y[k])
                    cy[k].append([curr_x[k], curr_y[k], IDS[k]])

        upper_pts = cx[0] + cx[1] + cy[0] + cy[1]
        return upper_pts + get_in_all_quadrants(upper_pts)

    # Contains slope of point visited in radians
    # unordered was much missed
    reflections = get_all_reflections()
    tracker = dict()

    def visited(a):
        '''
        returns whether the point is already counted
        '''
        return slope(a) in tracker

    def has_blocking_target(point):
        '''
        returns whether this point is
        blocking some other target in a good way
        '''
        return visited(point) and tracker[slope(point)][1] > euclid_distance(point)

    # First visit all our own reflections
    # and also let's visit targets, kill'em all
    # Unless it kills you

    for i in reflections:
        if reachable(i) and (not visited(i) or has_blocking_target(i)):
            tracker[slope(i)] = [i, euclid_distance(i)]

    return sum([(tracker[i][0][2] == GUARD) for i in tracker])


if __name__ == "__main__":
    dimensions = [2, 5]
    your_position = [1, 2]
    guard_position = [1, 4]
    distance = 11

    print(solution(dimensions, your_position, guard_position, distance), 27)

    dimensions = [300, 275]
    your_position = [150, 150]
    guard_position = [185, 100]
    distance = 500

    print(solution(dimensions, your_position, guard_position, distance), 9)

    dimensions = [3, 2]
    your_position = [1, 1]
    guard_position = [2, 1]
    distance = 4

    print(solution(dimensions, your_position, guard_position, distance), 7)

    dimensions = [23, 10]
    your_position = [6, 4]
    guard_position = [3, 2]
    distance = 23

    print(solution(dimensions, your_position, guard_position, distance), 8)

    dimensions = [1250, 1250]
    your_position = [1000, 1000]
    guard_position = [500, 400]
    distance = 10000

    print(solution(dimensions, your_position, guard_position, distance), 196)

    dimensions = [10, 10]
    your_position = [4, 4]
    guard_position = [3, 3]
    distance = 5000

    print(solution(dimensions, your_position, guard_position, distance), 739323)
