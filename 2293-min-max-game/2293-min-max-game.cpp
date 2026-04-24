class Solution {
public:
    vector<int>play(vector<int>& nums){
        int n=nums.size();
        vector<int>temp;
        int j=0;
        for(int i=0;i<nums.size();i+=2){
            if(j%2==0){
                int x = min(nums[i],nums[i+1]);
                temp.push_back(x);
            }else{
                int x = max(nums[i],nums[i+1]);
                temp.push_back(x);
            }
            j++;
        }
        return temp;
    }
    int minMaxGame(vector<int>& nums) {
        int n=nums.size();
        while(nums.size()>1){
            nums = play(nums);
        }
        return nums[0];
    }
};