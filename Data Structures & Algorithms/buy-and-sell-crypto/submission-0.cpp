class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b = prices[0];
        int p = 0;
        for (int i = 1; i < prices.size(); i++) {
            b = min(b, prices[i]);
            p = max(p, prices[i] - b);
        }
        return p;
    }
};
