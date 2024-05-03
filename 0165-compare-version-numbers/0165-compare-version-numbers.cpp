class Solution {
public:
    int compareVersion(string version1, string version2) {
        int ptr1_l = 0, ptr2_l = 0, ptr1_r = 0, ptr2_r = 0;
        int comparison = 0;
        while(ptr1_r <= version1.size() && ptr2_r <= version2.size())
        {
            if((ptr1_r < version1.size() && version1[ptr1_r] == '.') && (ptr2_r < version2.size() && version2[ptr2_r] == '.') || ptr1_r == version1.size() && ptr2_r == version2.size() || (ptr1_r < version1.size() && version1[ptr1_r] == '.') && ptr2_r == version2.size() || (ptr2_r < version2.size() && version2[ptr2_r] == '.') && ptr1_r == version1.size())
            {
                size_t pos;
                int rev1 = stoi(version1.substr(ptr1_l, ptr1_r - ptr1_l), &pos);
                int rev2 = stoi(version2.substr(ptr2_l, ptr2_r - ptr2_l), &pos);
                if(rev1 < rev2)
                {
                    comparison = -1;
                    break;
                }
                else if(rev1 > rev2)
                {
                    comparison = 1;
                    break;
                }
                else
                {
                    if((ptr1_r < version1.size() && version1[ptr1_r] == '.') && ptr2_r == version2.size())
                    {
                        for(; ptr1_r < version1.size(); ptr1_r++)
                        {
                            if(!(version1[ptr1_r] == '.' || version1[ptr1_r] == '0'))
                            {
                                comparison = 1;
                            }
                        }
                        break;
                    }
                    else if((ptr2_r < version2.size() && version2[ptr2_r] == '.') && ptr1_r == version1.size())
                    {
                        for(; ptr2_r < version2.size(); ptr2_r++)
                        {
                            if(!(version2[ptr2_r] == '.' || version2[ptr2_r] == '0'))
                            {
                                comparison = -1;
                            }
                        }
                        break;
                    }
                }
                ptr1_l = ptr1_r + 1;
                ptr2_l = ptr2_r + 1;
                ptr1_r++;
                ptr2_r++;
            }
            else
            {
                if(ptr1_r < version1.size() && version1[ptr1_r] != '.')
                {
                    ptr1_r++;
                }
                if(ptr2_r < version2.size() && version2[ptr2_r] != '.')
                {
                    ptr2_r++;
                }
            }
        }
        return comparison;
    }
};