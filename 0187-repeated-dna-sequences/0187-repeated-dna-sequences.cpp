class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_multimap<int,int> hashIndexesMap;
        int a = 7;
        int m = 1000000007;
        int k = 10;
        int hash = 0;
        vector<string> retVec;
        if(s.size() > k)
        {
            for(int nucleotideIndex = 0; nucleotideIndex < k; nucleotideIndex++)
            {
                hash += static_cast<int>(s[nucleotideIndex]&7)*pow(a,k-(nucleotideIndex+1));
            }
            hash = hash % m;
            hashIndexesMap.insert(make_pair(hash,0));
            for(int nucleotideIndex = 1; nucleotideIndex < s.size()-(k-1); nucleotideIndex++)
            {
                hash = static_cast<int>((hash-(static_cast<int>(s[nucleotideIndex-1]&7)*pow(a,k-1)))*a+static_cast<int>(s[nucleotideIndex+(k-1)]&7) % m);
                hashIndexesMap.insert(make_pair(hash,nucleotideIndex));
            }
            
            {
                auto mapIt = hashIndexesMap.begin();
                while(mapIt != hashIndexesMap.end())
                {
                    auto range = hashIndexesMap.equal_range((*mapIt).first);
                    unordered_set<string> repeatedStringsDetector;
                    unordered_set<string> repeatedStringsSet;
                    for(auto& index = range.first; index != range.second; index++)
                    {
                        string str = s.substr((*index).second,10);
                        if(!(repeatedStringsDetector.insert(str).second))
                        {
                            repeatedStringsSet.insert(str);
                        }
                    }
                    for(auto& str : repeatedStringsSet)
                    {
                        retVec.push_back(str);
                    }
                    mapIt = range.second;
                }
            }
        }
        return retVec;
    }
};