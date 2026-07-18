class Solution {
public:
    int findGCD(vector<int>& nums) {
        int s=nums[0] , l=nums[0];
        for(int x:nums){
            if(x>l)
                l = x;
            if(x<s)
                s = x;
        }
        return gcd(s,l);
    }
};