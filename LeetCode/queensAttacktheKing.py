# LC 1222
from math import atan2, hypot


class Solution:
    def queensAttacktheKing(self, queens: List[List[int]], king: List[int]) -> List[List[int]]:
        slopes = dict()
        final_points = dict()
        res = []
        allowed_angles = [atan2(1, 1), atan2(-1, -1), atan2(-1, 1), atan2(1, -1),
                          atan2(0, 1), atan2(1, 0), atan2(0, -1), atan2(-1, 0)]

        for queen in queens:
            deltaX = queen[0]-king[0]
            deltaY = queen[1]-king[1]

            dist = hypot(deltaY, deltaX)
            slope = atan2(deltaY, deltaX)

            if ((slope in slopes and slopes[slope] > dist) or (slope not in slopes)) and slope in allowed_angles:
                slopes[slope] = dist
                final_points[slope] = queen

        for i in final_points:
            res.append(final_points[i])
        return res
