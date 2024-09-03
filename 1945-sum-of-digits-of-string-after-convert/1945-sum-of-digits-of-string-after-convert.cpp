class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0;
        for(auto& character : s)
        {
            int num = character - '`';
            sum += num % 10 + (num / 10) % 10;
        }
        if(k > 1)
        {
            for(int i = 1; i < k; i++)
            {
                sum = sum % 10 + (sum / 10) % 10 + (sum / 100) % 10 + (sum / 1000) % 10;
            }
        }
        return sum;
    }
};