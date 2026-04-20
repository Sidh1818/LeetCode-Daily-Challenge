class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        long long miss = 1;
        long long ans=0;
        int patch=0,i=0;
        long long sum=0;
        for(int i=0;i<coins.size();i++){
            sum+=coins[i];
        }
        sort(coins.begin(),coins.end());
        while(miss<=sum){
            if(i<coins.size() && miss>=coins[i]){
                miss+=coins[i];
                i++;
            }
            else
                return miss;
        }
        return sum+1;
    }
};