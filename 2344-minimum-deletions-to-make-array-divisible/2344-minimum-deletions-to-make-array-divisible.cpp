class Solution {
public:
    int gd(int a,int b){
        while(b!=0){
            int temp = b;
            b = a%b;
            a = temp;
        }
        return a;
    }


    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int g=0;
        for(int i=0;i<numsDivide.size();i++){
            g = gd(g,numsDivide[i]);
        }

        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(g%nums[i]==0)
                return i;
        }
        return -1;
    }
};