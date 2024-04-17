class Solution {
private:
    vector<string> smallestFromLeafHelper(TreeNode* root, int& depth)
    {
        vector<string> stringCollector;
        if(!(root->left || root->right))
        {
            string newString;
            newString.push_back(root->val+97);
            stringCollector.push_back(newString);
        }
        else
        {
            string leftStr;
            if(root->left)
            {
                vector<string> returnedVec = smallestFromLeafHelper(root->left, ++depth);
                stringCollector.insert(end(stringCollector), begin(returnedVec), end(returnedVec));
                depth--;
            }
            if(depth == 1)
            {
                if(!stringCollector.empty())
                {
                    for(auto& str : stringCollector)
                    {
                        str.push_back(root->val+97);
                    }
                    string* smallest = &stringCollector[0];
                    for(int strIndex = 1; strIndex < stringCollector.size(); strIndex++)
                    {
                        smallest = *smallest < stringCollector[strIndex] ? smallest : &stringCollector[strIndex];
                    }
                    leftStr = *smallest;
                    stringCollector.clear();
                }
            }
            if(root->right)
            {
                vector<string> returnedVec = smallestFromLeafHelper(root->right, ++depth);
                stringCollector.insert(end(stringCollector), begin(returnedVec), end(returnedVec));
                depth--;
            }
            for(auto& str : stringCollector)
            {
                str.push_back(root->val+97);
            }
            if(depth == 1)
            {
                if(!leftStr.empty())
                {
                    stringCollector.push_back(leftStr);
                }
            }
        }
        return stringCollector;
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        vector<string> stringCollector;
        int depth = 1;
        stringCollector = smallestFromLeafHelper(root, depth);
        string* smallest = &stringCollector[0];
        for(int strIndex = 0; strIndex < stringCollector.size(); strIndex++)
        {
            smallest = *smallest < stringCollector[strIndex] ? smallest : &stringCollector[strIndex];
        }
        return *smallest;
    }
};