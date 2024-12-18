class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        for(int index = 0; index < prices.size(); index++)
        {
            for(int substractionIndex = index + 1; substractionIndex < prices.size(); substractionIndex++)
            {
                if(prices[substractionIndex] <= prices[index])
                {
                    prices[index] -= prices[substractionIndex];
                    break;
                }
            }
        }
        return prices;
    }
};
