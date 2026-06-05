class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        /*
        unordered_map<int,int>freq;
        for(int a:nums)
            freq[a]++;
        int occurence = nums.size()/3;
        vector<int>ans;
        for(auto &a:freq){
            if(a.second > occurence)
                ans.push_back(a.first);
        }
        return ans;
        */
        int candidate1 = 0 , candidate2 = 0;
        int cnt1=0, cnt2=0;

        for(int a:nums){
            if(a == candidate1)
                cnt1++;
            else if(a == candidate2)
                cnt2++;
            else if(cnt1 == 0){
                candidate1 = a;
                cnt1 = 1;
            }
            else if(cnt2 == 0){
                candidate2 = a;
                cnt2 = 1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }


        cnt1=0,cnt2=0;
        for(int a:nums){
            if(a == candidate1)
                cnt1++;
            else if(a == candidate2)
                cnt2++;
        }

        vector<int>ans;

        if(cnt1 > nums.size()/3)
            ans.push_back(candidate1);

        if(cnt2 > nums.size()/3)
            ans.push_back(candidate2);

        return ans;
    }
};