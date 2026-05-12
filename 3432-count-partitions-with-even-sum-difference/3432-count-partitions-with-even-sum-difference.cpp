class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size(),ans=0;
        vector<int>prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        vector<int>suffix(n);
        suffix[n-1] = nums[n-1];

        for(int i=n-2;i>=0;i--){
            suffix[i] = suffix[i+1]+nums[i];
        }

        for(int i=0;i<n-1;i++){
            if(abs(prefix[i]-suffix[i+1])%2==0)
                ans++;
        }
        return ans;
    }
};