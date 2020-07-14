class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angleOfMinute = (minutes*5.5);
        double angleOfHour = (hour%12)*30;
        double res = fmod(abs(angleOfHour-angleOfMinute), 360.0);
        double fin = min(res, 360.0-res);
        return fin > 0 ? fin : 0;
    }
};
