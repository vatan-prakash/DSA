class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        int minsofar=prices[0];
        int n=prices.size();
        for(int i=0;i<n;i++){
            minsofar=min(prices[i],minsofar);
            int profit=prices[i]-minsofar; //if same day sell kia to 0 aega
            maxprofit=max(maxprofit, profit);
        }
        return maxprofit;
    }
};