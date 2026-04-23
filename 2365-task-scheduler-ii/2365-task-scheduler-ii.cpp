class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int,long long>mp;
        long long currDay = 0;
        for(int task:tasks){
            currDay++;
            if(mp.count(task)){
                currDay = max(currDay,mp[task]);
            }
            mp[task] = currDay+space+1;
        }
        return currDay;
    }
};