/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void isEvenOddTreeHelper(TreeNode* root, int& level, vector<int>& orderComparisonVector, bool& isEven)
    {
        if(isEven != false)
        {
            level++;
            if(orderComparisonVector.size() <= level)
            {
                orderComparisonVector.push_back(0);
            }
            if(level%2 == 0 && orderComparisonVector[level] < root->val && root->val%2 == 1)
            {
                orderComparisonVector[level] = root->val;
            }
            else if(level%2 == 1 && (orderComparisonVector[level] > root->val || orderComparisonVector[level] == 0) && root->val%2 == 0)
            {
                orderComparisonVector[level] = root->val;
            }
            else
            {
                isEven = false;
            }
            if(root->left)
            {
                isEvenOddTreeHelper(root->left, level, orderComparisonVector, isEven);
            }
            if(root->right)
            {
                isEvenOddTreeHelper(root->right, level, orderComparisonVector, isEven);
            }
            level--;
        }
    }
public:
    bool isEvenOddTree(TreeNode* root) {
        int lvl = -1;
        bool res = true;
        vector<int> helperVector;
        isEvenOddTreeHelper(root, lvl, helperVector, res);
        return res;
    }
};