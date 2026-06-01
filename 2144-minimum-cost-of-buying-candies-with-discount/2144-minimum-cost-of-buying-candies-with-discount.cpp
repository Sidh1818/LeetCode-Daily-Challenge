class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int ans=0,cnt=1;
        int n=cost.size();
        for(int i=n-1;i>=0;i--){
            if(cnt%3!=0)
                ans+=cost[i];
            cnt++;
        }
        return ans;
    }
};