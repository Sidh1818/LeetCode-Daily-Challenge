class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>res;
        sort(intervals.begin(),intervals.end());
        int strt1 = intervals[0][0];
        int end1 = intervals[0][1];

        for(int i=1;i<intervals.size();i++){
            int strt2 = intervals[i][0];
            int end2 = intervals[i][1];

            if(end1 >= strt2){
                strt1 = strt1;
                end1 = max(end1,end2);
                continue;
            }

            res.push_back({strt1,end1});

            strt1 = strt2;
            end1 = end2;
        }
        res.push_back({strt1,end1});
        return res;
    }
};