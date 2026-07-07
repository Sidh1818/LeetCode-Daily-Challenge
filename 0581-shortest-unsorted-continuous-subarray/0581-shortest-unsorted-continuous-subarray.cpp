class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left = -1 , right = -1;
        int maxEle = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<maxEle)
                right = i;
            else
                maxEle = nums[i];
        }
        int n = nums.size();
        int minEle = nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(nums[i]<=minEle)
                minEle = nums[i];
            else
                left = i;
        }
        if(right == -1)
            return 0;
        return right - left + 1;
    }
};