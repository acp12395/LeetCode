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
    void findBottomLeftValueHelper(TreeNode* root, int& level, int& bottomLeftValue, int& maxLeftLevel)
    {
        level++;
        if(level > maxLeftLevel)
        {
            maxLeftLevel = level;
            bottomLeftValue = root->val;
        }
        if(root->left)
        {
            findBottomLeftValueHelper(root->left, level, bottomLeftValue, maxLeftLevel);
        }
        if(root->right)
        {
            findBottomLeftValueHelper(root->right, level, bottomLeftValue, maxLeftLevel);
        }
        level--;
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        int lvl = -1, res, maxLeftLvl = -1;
        findBottomLeftValueHelper(root, lvl, res, maxLeftLvl);
        return res;
    }
};