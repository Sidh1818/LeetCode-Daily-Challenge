class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int left=0,right=0,mid=0;
        vector<int>lesser,greater;
        int equal = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==pivot)
                equal++;
            else if(nums[i]>pivot)
                greater.push_back(nums[i]);
            else
                lesser.push_back(nums[i]);
        }

        vector<int>ans;
        for(int i=0;i<lesser.size();i++)
            ans.push_back(lesser[i]);
        while(equal!=0){
            ans.push_back(pivot);
            equal--;
        }
        for(int i=0;i<greater.size();i++)
            ans.push_back(greater[i]);
        return ans;
    }
};