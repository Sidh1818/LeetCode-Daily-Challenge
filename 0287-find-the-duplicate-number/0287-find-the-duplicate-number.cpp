class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<high){
            int cnt=0;
            int mid = low+(high-low)/2;

            for(int i=0;i<n;i++){
                if(nums[i]<=mid)
                    cnt++;
            }

            if(cnt<=mid)
                low = mid+1;
            else
                high = mid;
        }
        return low;
    }
};