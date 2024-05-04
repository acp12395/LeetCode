class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        vector<int> sortedPeople = people;
        sort(sortedPeople.begin(), sortedPeople.end());
        int boats = 0;
        int left = 0, right = sortedPeople.size() - 1;
        while(right - left > -1)
        {
            if(sortedPeople[right] + sortedPeople[left] <= limit)
            {
                boats++;
                left++;
                right--;
            }
            else
            {
                boats++;
                right--;
            }
        }
        return boats;
    }
};