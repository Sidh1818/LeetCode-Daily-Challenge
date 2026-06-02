class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprofit = prices[0];
        int profit = 0;

        for(int i=1;i<prices.size();i++){
            if(minprofit>prices[i])
                minprofit = prices[i];
            else
                profit = max(profit,prices[i]-minprofit);
        }
        return profit;
    }
};