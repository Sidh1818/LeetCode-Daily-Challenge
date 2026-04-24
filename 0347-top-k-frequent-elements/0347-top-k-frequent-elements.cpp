class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }

        priority_queue<pair<int,int>>pq;
        for(auto it:freq){
            int y = it.second;
            int x = it.first;
            pq.push({y,x});
        }
        vector<int>ans;
        for(int i=0;i<k;i++){
            auto t = pq.top();
            pq.pop();
            ans.push_back(t.second);
        }
        return ans;
    }
};