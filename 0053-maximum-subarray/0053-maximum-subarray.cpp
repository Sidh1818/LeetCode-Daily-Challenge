class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestsum = nums[0];
        int ans = nums[0];
        for(int i=1;i<nums.size();i++){
            int v1 = nums[i];
            int v2 = bestsum + nums[i];
            bestsum = max(v1,v2);

            ans = max(ans,bestsum);
        }
        return ans;
    }
};