class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // This code is having the time complexity O(N2).. So going with the optimal approach..
        /*
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return {0,0};
        */
        //using the unordered map..
        unordered_map<int,int>mp;//to keep the pair
        for(int i=0;i<nums.size();i++){
            if(mp.find(target-nums[i]) != mp.end()){
                return {i,mp[target-nums[i]]};
            }
            else
                mp[nums[i]]=i;
        }
        return {0,0};
    }
};