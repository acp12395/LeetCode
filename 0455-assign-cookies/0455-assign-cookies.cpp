class Solution
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        int contentChildren = 0;
        vector<int> l_s = s;
        vector<int> l_g = g;
        sort(l_s.begin(),l_s.end());
        sort(l_g.begin(),l_g.end());
        int sizeForStart = 0;
        int lastSizeIndex;
        for(auto& greed : l_g)
        {
            for(int sizeIndex = sizeForStart; sizeIndex < l_s.size(); sizeIndex++)
            {
                lastSizeIndex = sizeIndex;
                if(l_s[sizeIndex] >= greed)
                {
                    contentChildren++;
                    break;
                }
            }
            if(lastSizeIndex == (l_s.size() - 1))
            {
                break;
            }
            else
            {
                sizeForStart = lastSizeIndex + 1;
            }
        }
        return contentChildren;
    }
};