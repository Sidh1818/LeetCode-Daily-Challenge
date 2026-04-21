class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int target=sum-x;
        if(target<0)
            return -1;
        if(target==0)
            0;
        
        int left=0,right=0,curr_sum=0;
        int len=-1;
        while(right<nums.size()){
            curr_sum+=nums[right];
            while(left<=right &&curr_sum>target){
                curr_sum-=nums[left];
                left++;
            }
            if(curr_sum==target){
                int x = right-left+1;
                len = max(len,x);
            }
            right++;
        }
        if(len==-1)
            return -1;
        return n-len;
    }
};