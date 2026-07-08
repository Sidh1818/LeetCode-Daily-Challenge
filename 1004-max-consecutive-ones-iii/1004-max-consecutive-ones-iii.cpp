class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros=0,low=0,high=0,ans=0,n=nums.size();

        for(high=0;high<n;high++){
            if(nums[high]==0)
                zeros++;
            while(zeros>k){
                if(nums[low]==0)
                    zeros--;
                low++;
            }
            ans = max(ans,high-low+1);
        }
        return ans;
        /*
        int zeros = 0 ,ones = 0;
        int diff=0,ans=0;
        int low=0,high=0,n=nums.size();
        for(high=0;high<n;high++){
            if(nums[high]==1)
                ones++;
            else
                zeros++;
            int len = high-low+1;
            int maxcnt = max(zeros,ones);

            diff = len-maxcnt;

            if(diff>k){
                if(nums[low]==1)
                    ones--;
                else
                    zeros--;
                low++;

                int len = high-low+1;
                int maxcnt = max(ones,zeros);

                diff = len-maxcnt;
            }

            len = high-low+1;
            ans = max(ans,len);
        }
        return ans;
        */
    }
};