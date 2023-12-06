class Solution {
public:
    int totalMoney(int n) {
        if(n == 1)
        {
            return 1;
        }
        else
        {
            return totalMoney(n - 1) + n - 6*((n-1)/7);
        }
    }
};