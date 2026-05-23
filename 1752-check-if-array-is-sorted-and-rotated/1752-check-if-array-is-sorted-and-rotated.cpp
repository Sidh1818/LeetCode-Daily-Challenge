class Solution {
public:
    bool check(vector<int>& nums) {
        int breaks=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                breaks++;
                if(breaks>1)
                    return false;
            }
        }
        int n=nums.size();
        if(nums[n-1]>nums[0] && breaks==1)
            return false;
        return true;
    }
};