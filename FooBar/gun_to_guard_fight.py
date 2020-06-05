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


def unique_hash(pt):
    '''
    return unique value for pt
    '''
    return '{}#{}'.format(pt[0], pt[1])


def reflect(pt, mirror):
    '''
    return reflection of point 
    (normally with vertical axes and 0)
    '''
    return mirror*TWO - pt


def solution(dim, you, guard, distance):
    d_two = distance**TWO

    def not_me(dst, src=you):
        '''
        returns whether this is same point
        as where we began.
        '''
        return (dst[0] != src[0]) and (dst[1] != src[1])

    def euclid_distance(dst, src=you):
        '''
        returns euclid_distance of src from dst.
        If dst is not given it is treated as origin
        '''
        return sum([(dst[i]-src[i])**TWO for i in range(TWO)])

    def reachable(a):
        '''
        returns whether or not beam reaches guard
        '''
        return d_two >= euclid_distance(a)

    # Contains hash separated coordinates which are visited
    # unordered was much missed
    history = set()

    def get_all_reflections(point):
        '''
        returns position of beam after reflection in room
        '''
        refs = []
        refs.append((reflect(point[0], 0), point[1]))
        refs.append((point[0], reflect(point[1], 0)))
        refs.append((reflect(point[0], dim[0]), point[1]))
        refs.append((point[0], reflect(point[1], dim[1])))
        return refs

    def visited(a):
        '''
        returns whether the point is already counted
        '''
        return unique_hash(a) in history

    def visit(a):
        '''
        visits a point
        '''
        history.add(unique_hash(a))

    # since the valid ones are in history
    pseudo_valid_pts_q = []
    if reachable(guard):
        pseudo_valid_pts_q.append(guard)
    while len(pseudo_valid_pts_q):
        curr_pt = pseudo_valid_pts_q.pop(0)
        if reachable(curr_pt) and not visited(curr_pt):
            visit(curr_pt)
            for rfl in get_all_reflections(curr_pt):
                if not_me(rfl):
                    pseudo_valid_pts_q.append(rfl)

    return len(history)



if __name__ == "__main__":
    # dimensions = [2, 5]
    # your_position = [1, 2]
    # guard_position = [1, 4]
    # distance = 11

    # dimensions = [300, 275]
    # your_position = [150, 150]
    # guard_position = [185, 100]
    # distance = 500

    dimensions = [3, 2]
    your_position = [1, 1]
    guard_position = [2, 1]
    distance = 4
    print(solution(dimensions, your_position, guard_position, distance))
