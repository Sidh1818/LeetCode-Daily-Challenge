class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int left=0;
        for(int i=0;i<nums.size();i++){
            if(nums[left]!=nums[i]){
                nums[++left] = nums[i];
            }
        }
        return left+1;
    }
};