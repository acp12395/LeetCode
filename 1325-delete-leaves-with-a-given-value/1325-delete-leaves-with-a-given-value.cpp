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
    void removeLeafNodesHelper(TreeNode*& root, int& target)
    {
        if(root->left)
        {
            removeLeafNodesHelper(root->left, target);
        }
        if(root->right)
        {
            removeLeafNodesHelper(root->right, target);
        }
        if(root->right == nullptr && root->left == nullptr && root->val == target)
        {
            root = nullptr;
        }
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        removeLeafNodesHelper(root, target);
        return root;
    }
};