class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        unordered_map<double, vector<int>> fractionOperandsMap;
        vector<double> fractions;
        for(int i = 0; i < arr.size() - 1; i++)
        {
            for(int j = arr.size() - 1; j > i; j--)
            {
                double fraction = static_cast<double>(arr[i])/arr[j];
                fractions.push_back(fraction);
                fractionOperandsMap[fraction].push_back(arr[i]);
                fractionOperandsMap[fraction].push_back(arr[j]);
            }
        }
        sort(fractions.begin(), fractions.end());
        return fractionOperandsMap[fractions[k - 1]];
    }
};