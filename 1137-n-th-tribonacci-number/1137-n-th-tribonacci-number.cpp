class Solution {
private:
    unordered_map<int,int> nTribonacciMap;
public:
    int tribonacci(int n) {
        if(n == 0)
        {
            return 0;
        }
        else if(n == 1 || n == 2)
        {
            return 1;
        }
        else
        {
            if(nTribonacciMap.count(n) != 1)
            {
                nTribonacciMap[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
            }
        }
        return nTribonacciMap[n];
    }
};