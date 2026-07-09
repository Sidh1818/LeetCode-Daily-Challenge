class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty())
            return {newInterval};

        vector<vector<int>>ans,res;
        bool insert = false;
        for(int i=0;i<intervals.size();i++){
            if(insert == false && newInterval[0]<=intervals[i][0]){
                res.push_back(newInterval);
                insert = true;
            }
            res.push_back(intervals[i]);
        }
        if(!insert)
            res.push_back(newInterval);

        int strt1 = res[0][0];
        int end1 = res[0][1];

        for(int i=1;i<res.size();i++){
            int strt2 = res[i][0] , end2 = res[i][1];

            if(end1>=strt2){
                strt1 = strt1;
                end1 = max(end1,end2);
                continue;
            }

            ans.push_back({strt1,end1});
            strt1 = strt2;
            end1 = end2;
        }
        ans.push_back({strt1,end1});
        return ans;
    }
};