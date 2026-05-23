class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int zrs = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
                zrs++;
        }
        if(nums.size()==zrs)
            return 0;
        int a=0;
        for(int i=nums.size()-1;i>=nums.size()-zrs;i--){
            if(nums[i]==0)
                a++;
        }
        return zrs-a;
    }
};