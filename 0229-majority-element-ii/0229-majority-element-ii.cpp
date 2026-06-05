class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int a:nums)
            freq[a]++;
        int occurence = nums.size()/3;
        vector<int>ans;
        for(auto &a:freq){
            if(a.second > occurence)
                ans.push_back(a.first);
        }
        return ans;
    }
};