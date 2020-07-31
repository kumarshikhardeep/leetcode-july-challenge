class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minHandAngle = minutes * 6;
        if(hour == 12)
            hour = 0;
        double m = minutes*1.0;
        
        double hourHandAngle = (hour * 30) + (m * 0.5);
        double ans = abs(minHandAngle - hourHandAngle);
        return min(ans, 360.0-ans);
    }
};
