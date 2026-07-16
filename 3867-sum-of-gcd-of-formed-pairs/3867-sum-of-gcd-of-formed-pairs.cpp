class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int>gcdd;
        int n=nums.size();
        int mx = nums[0],g;
        for(int i=0;i<n;i++){
            mx = max(mx,nums[i]);
            g = gcd(nums[i],mx);
            gcdd.push_back(g);
        }
        sort(gcdd.begin(),gcdd.end());

        int right = gcdd.size()-1;
        int left=0;
        long long ans=0,a;
        while(left<right){
            a = gcd(gcdd[left],gcdd[right]);
            ans+=a;
            left++;
            right--;
        }
        return ans;
    }
};