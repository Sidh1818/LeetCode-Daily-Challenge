class Solution {
public:
    int firstTime(vector<int>&strt1,vector<int>dur1,vector<int>&strt2,vector<int>&dur2){
        int finish1 = INT_MAX;
        for(int i=0;i<strt1.size();i++){
            finish1 = min(finish1,strt1[i]+dur1[i]);
        }
        int finish2 = INT_MAX;
        for(int i=0;i<strt2.size();i++){
            finish2 = min(finish2,max(finish1,strt2[i])+dur2[i]);
        }
        return finish2;
    }


    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int case1 = firstTime(landStartTime,landDuration,waterStartTime,waterDuration);
        int case2 = firstTime(waterStartTime,waterDuration,landStartTime,landDuration);

        return min(case1,case2);
    }
};