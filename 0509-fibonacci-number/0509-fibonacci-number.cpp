class Solution {
private:
    map<int, int> nFibMap;
public:
    int fib(int n) {
        if(n == 0 || n == 1)
        {
            return n;
        }
        else
        {
            if(nFibMap.count(n) == 1)
            {
                return nFibMap[n];
            }
            nFibMap[n] = fib(n - 1) + fib(n - 2);
            return nFibMap[n];
        }
    }
};