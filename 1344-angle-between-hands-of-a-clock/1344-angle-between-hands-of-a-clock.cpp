class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hr = (hour%12) * 30;
        double mn = minutes * 6;

        double diff = minutes / 2.0;

        double ans = abs(hr - mn + diff);

        return min(ans,360.0 - ans);
    }
};