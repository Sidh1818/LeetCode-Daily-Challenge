class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0,right=0,current_sum=0,min_length=INT_MAX;
        int n=nums.size();
        while(right<n){
            current_sum+=nums[right];
            while(current_sum>=target){
                int x = right-left+1;
                min_length = min(min_length,x);
                current_sum-=nums[left];
                left++;
            }
            right++;
        }
        return min_length==INT_MAX?0:min_length;
        /*
        vector<int>prefix;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            prefix.push_back(sum);
        }
        
        int s2=0;
        vector<int>suffix;
        for(int i=n-1;i>=0;i--){
            s2+=nums[i];
            suffix.push_back(s2);
        }

        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(prefix[i]>=target){
                ans=i+1;
                break;
            }
        }
        int ans2=INT_MAX;
        for(int i=0;i<n;i++){
            if(suffix[i]>=target){
                ans2=i+1;
                break;
            }
        }
        if(ans == INT_MAX && ans2==INT_MAX)
            return 0;
        return min(ans,ans2);
        */
        
    }
};