class Solution {
private:
    map<int, int> indexMinCostMap;
    int minCostClimbingStairsHelper(vector<int>& cost, int index)
    {
        int retVal = 0;
        if(index == 0 || index == 1)
        {
            retVal += cost[index];
        }
        else
        {
            if(indexMinCostMap.count(index) == 0)
            {
                indexMinCostMap[index] = min(minCostClimbingStairsHelper(cost, index - 1), minCostClimbingStairsHelper(cost, index - 2));
            }
            retVal = indexMinCostMap[index];
            if(index < cost.size())
            {
                retVal += cost[index];
            }
        }
        return retVal;
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        return minCostClimbingStairsHelper(cost, cost.size());
    }
};