class Solution {
private:
    int nodeCount;
    int oddCountCount;
    unordered_map<int,int> digitCountMap;
    int pseudoPalindromicPathsHelper (TreeNode* root, int res = 0)
    {
        int retVal;
        nodeCount++;
        digitCountMap[root->val]++;
        if(digitCountMap[root->val]%2 == 1)
        {
            oddCountCount++;
        }
        else
        {
            oddCountCount--;
        }
        if(root->left || root->right)
        {
            if(root->left)
            {
                res = pseudoPalindromicPathsHelper(root->left,res);
            }
            if(root->right)
            {
                res = pseudoPalindromicPathsHelper(root->right,res);
            }
        }
        else
        {
            if(nodeCount%2 == 1)
            {
                if(oddCountCount == 1)
                {
                    res++;
                }
            }
            else
            {
                if(oddCountCount == 0)
                {
                    res++;
                }
            }
        }
        if(digitCountMap[root->val]%2 == 1)
        {
            oddCountCount--;
        }
        else
        {
            oddCountCount++;
        }
        digitCountMap[root->val]--;
        nodeCount--;
        retVal = res;
        return retVal;
    }
public:
    Solution() : nodeCount(0),oddCountCount(0){}
    int pseudoPalindromicPaths (TreeNode* root)
    {
        return pseudoPalindromicPathsHelper(root);
    }
};