class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int leftOver;
        int firstChocolatePrice = INT_MAX, secondChocolatePrice = INT_MAX;
        for(auto& price : prices)
        {
            if(price < firstChocolatePrice || price < secondChocolatePrice)
            {
                if(firstChocolatePrice > secondChocolatePrice)
                {
                    firstChocolatePrice = price;
                }
                else
                {
                    secondChocolatePrice = price;
                }
            }
        }
        leftOver = money - (firstChocolatePrice + secondChocolatePrice);
        return leftOver >= 0 ? leftOver : money;
    }
};