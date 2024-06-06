class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(), hand.end());
        unordered_map<int, int> valueCountMap;
        int maxVal = 0;
        for(auto& card : hand)
        {
            valueCountMap[card]++;
            maxVal = maxVal > card ? maxVal : card;
        }
        for(int pivotVal = *upper_bound(hand.begin(),hand.end(),-1); pivotVal + groupSize - 1 <= maxVal; pivotVal = pivotVal == maxVal ? pivotVal + 1 : *upper_bound(hand.begin(),hand.end(),pivotVal))
        {
            if(valueCountMap.count(pivotVal) > 0)
            {
                int firstCount = valueCountMap[pivotVal];
                bool exit = false;
                for(int i = pivotVal; i < pivotVal + groupSize; i++)
                {
                    valueCountMap[i] -= firstCount;
                    if(valueCountMap[i] == 0)
                    {
                        valueCountMap.erase(i);
                    }
                    else if(valueCountMap[i] < 0)
                    {
                        exit = true;
                        break;
                    }
                }
                if(exit)
                {
                    break;
                }
            }
        }
        return valueCountMap.empty();
    }
};