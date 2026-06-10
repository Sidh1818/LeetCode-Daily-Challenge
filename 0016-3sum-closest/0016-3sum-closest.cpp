class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n-2;i++){
            int start=i+1,end=n-1;
            while(start<end){
                int curr = nums[i]+nums[start]+nums[end];
                if(abs(ans-target)>abs(curr-target))
                    ans=curr;

                if(curr>target)
                    end--;
                else if(curr<target)
                    start++;
                else
                    return curr;
            } 
        }
        return ans;
    }
};