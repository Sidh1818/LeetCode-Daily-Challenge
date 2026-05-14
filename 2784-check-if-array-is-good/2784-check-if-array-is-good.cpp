class Solution {
public:
    bool isGood(vector<int>& nums) {
        unordered_map<int,int>freq;
        int m = nums[0];
        int n=nums.size();
        for(int n:nums){
            freq[n]++;
            m = max(m,n);
        }
        /*
        for(auto &f:freq){
            if(f.first!=m){
                if(f.second!=1)
                    return false;
            }
        }
        */

        if(m!=n-1)
            return false;
        for(int i=1;i<m;i++){
            if(freq[i]!=1)
                return false;
        }
        int mx = nums.size();
        if(freq[m]!=2)
            return false;
        return true;
    }
};