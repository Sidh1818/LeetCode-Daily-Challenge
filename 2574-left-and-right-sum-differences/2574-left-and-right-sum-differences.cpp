class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        /*
        int n=nums.size();
        vector<int>ans(n,0);
        vector<int>left(n,0);
        vector<int>right(n,0);
        for(int i=1;i<n;i++){
            left[i] = left[i-1]+nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            right[i] = right[i+1]+nums[i+1];
        }

        for(int i=0;i<n;i++){
            ans[i] = abs(right[i]-left[i]);
        }
        return ans;
        */

        int sum=0,left=0,right,x;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];

        for(int i=0;i<nums.size();i++){
            right = sum - left - nums[i];
            x = abs(left - right);
            ans.push_back(x);
            left += nums[i];
        }
        return ans;
    }
};