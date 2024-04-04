class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int maxDepth = 0;
        for(auto& character : s)
        {
            if(character == '(')
            {
                depth++;
            }
            else if(character == ')')
            {
                depth--;
            }
            maxDepth = maxDepth > depth ? maxDepth : depth;
        }
        return maxDepth;
    }
};