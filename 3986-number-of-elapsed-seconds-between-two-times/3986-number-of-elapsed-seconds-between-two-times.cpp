class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int strtHr = (startTime[0]-'0')*10 + startTime[1]-'0';
        int strtMin = (startTime[3]-'0')*10 + startTime[4]-'0';
        int strtSec = (startTime[6]-'0')*10 + startTime[7]-'0';

        int endHr = (endTime[0]-'0')*10 + endTime[1]-'0';
        int endMin = (endTime[3]-'0')*10 + endTime[4]-'0';
        int endSec = (endTime[6]-'0')*10 + endTime[7]-'0';

        int ans = 0;
        if(strtSec>endSec){
            endMin--;
            endSec+=60;
        }
        ans+=abs(strtSec-endSec);

        if(strtMin>endMin){
            endHr--;
            endMin+=60;
        }
        ans=ans+(abs(strtMin - endMin)*60);

        ans+=(abs(strtHr - endHr)*60*60);
        return ans;
    }
};