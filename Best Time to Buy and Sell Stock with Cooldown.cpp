class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int sell = 0;
        int sell_pre = 0;
        int buy = INT_MIN;
        int buy_pre = buy;
        for(int price:prices)
        {
            buy_pre = buy;
            buy = max(buy_pre,sell_pre-price);
            sell_pre = sell;
            sell = max(sell_pre,buy_pre+price);
        }
        return sell;
    }
};
