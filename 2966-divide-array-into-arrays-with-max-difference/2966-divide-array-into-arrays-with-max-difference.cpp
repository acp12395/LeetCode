class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<int> numbers = nums;
        vector<vector<int>> retVec;
        sort(numbers.begin(),numbers.end());
        int prev = 0, prevPrev = 0, newVecNeeded, counter = 0;
        for(auto& num : numbers)
        {
            newVecNeeded = counter%3;
            if(newVecNeeded == 0)
            {
                vector<int> newVector;
                retVec.push_back(newVector);
                prev = num;
                prevPrev = num;
            }
            if(((num - prev) <= k) && ((num - prevPrev) <= k))
            {
                retVec.back().push_back(num);
            }
            else
            {
                retVec.clear();
                break;
            }
            prevPrev = prev;
            prev = num;
            counter++;
        }
        return retVec;
    }
};