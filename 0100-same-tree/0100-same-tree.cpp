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
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool retVal = true;
        if(p == nullptr || q == nullptr)
        {
            if(!(p == nullptr && q == nullptr))
            {
                retVal = false;
            }
        }
        else if(!(p->val == q->val))
        {
            retVal = false;
        }
        else
        {
            retVal &= isSameTree(p->left, q->left);
            retVal &= isSameTree(p->right, q->right);
        }
        return retVal;
    }
};