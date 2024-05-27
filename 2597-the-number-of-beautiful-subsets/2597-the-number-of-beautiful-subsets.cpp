class Solution {
private:
    int countBeautifulSubsets(vector<int>& nums, int& k, int index, unordered_map<int, int>& numCountMap)
    {
        if(index == nums.size())
        {
            return 1;
        }
        else
        {
            int count = 0;
            count = countBeautifulSubsets(nums, k, index + 1, numCountMap);
            if(numCountMap[nums[index] - k] == 0)
            {
                numCountMap[nums[index]]++;
                count += countBeautifulSubsets(nums, k, index + 1, numCountMap);
                numCountMap[nums[index]]--;
            }
            return count;
        }
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> numCountMap;
        vector<int> orderedNums = nums;
        sort(orderedNums.begin(), orderedNums.end());
        return countBeautifulSubsets(orderedNums, k, 0, numCountMap) - 1;
    }
};