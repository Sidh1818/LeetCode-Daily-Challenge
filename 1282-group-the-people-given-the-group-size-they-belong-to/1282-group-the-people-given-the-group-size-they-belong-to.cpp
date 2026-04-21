class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<groupSizes.size();i++){
            pq.push({groupSizes[i],i});
        }

        vector<vector<int>>ans;
        while(!pq.empty()){
            int x = pq.top().first;
            vector<int>ans1;
            for(int i=0;i<x;i++){
                ans1.push_back(pq.top().second);
                pq.pop();
            }
            ans.push_back(ans1);
        }
        return ans;
    }
};