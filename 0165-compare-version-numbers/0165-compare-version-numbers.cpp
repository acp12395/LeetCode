class Solution {
public:
    int compareVersion(string version1, string version2) {
        int index1 = 0;
        int index2 = 0;
        while(index1 < version1.size() && index2 < version2.size() && index1 != string::npos && index2 != string::npos)
        {
            string::size_type point1 = version1.find(".", index1);
            string::size_type point2 = version2.find(".", index2);
            if(point1 == string::npos)
            {
                point1 = static_cast<string::size_type>(version1.size());
            }
            if(point2 == string::npos)
            {
                point2 = static_cast<string::size_type>(version2.size());
            }
            int rev1 = stoi(version1.substr(index1, static_cast<int>(point1 - index1)));
            int rev2 = stoi(version2.substr(index2, static_cast<int>(point2 - index2)));
            if(rev1 < rev2)
            {
                return -1;
            }
            else if(rev1 > rev2)
            {
                return 1;
            }
            index1 = static_cast<int>(point1) + 1;
            index2 = static_cast<int>(point2) + 1;
        }
        for(; index1 < version1.size(); index1++)
        {
            char character = version1[index1];
            if(character != '.' && character != '0')
            {
                return 1;
            }
        }
        for(; index2 < version2.size(); index2++)
        {
            char character = version2[index2];
            if(character != '.' && character != '0')
            {
                return -1;
            }
        }
        return 0;
    }
};