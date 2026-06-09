class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mn = nums[0] , mx = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<mn)
                mn = nums[i];
            if(nums[i]>mx)
                mx = nums[i];
        }
        return (long long)(mx - mn) * k;
    }
};