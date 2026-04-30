class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int a:nums)
            mp[a]++;
        if(k>=n){
            int ans=-1;
            for(auto &it:mp){
                ans = max(ans,it.first);
            }
            return ans;
        }
        if(k==1 || k==nums.size()){
            int ans=-1;
            for(auto &it:mp){
                if(it.second == 1)
                    ans = max(ans,it.first);
            }
            return ans;
        }
        else{
            int ans=-1;
            int first = nums[0];
            int last = nums[n-1];

            if(mp[first]==1 && mp[last]==1)
                return max(first,last);
            else if(mp[first]==1)
                return first;
            else if(mp[last]==1)
                return last;
        }
        return -1;
    }
};