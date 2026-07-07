class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>neg,pos,ans;
        for(int x:nums){
            if(x<0)
                neg.push_back(x*x);
            else
                pos.push_back(x*x);
        }

        int left=0,right=neg.size()-1,i=0;
        while(left<pos.size() && right>=0){
            if(pos[left]<neg[right]){
                ans.push_back(pos[left]);
                left++;
            }
            else{
                ans.push_back(neg[right]);
                right--;
            }
        }

        while(left<pos.size()){
            ans.push_back(pos[left]);
            left++;
        }

        while(right>=0){
            ans.push_back(neg[right]);
            right--;
        }
        return ans;
    }
};