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
    int sumOfLeftLeavesHelper(TreeNode* root, bool isLeft)
    {
        int left = 0, right = 0;
        if(root->left == nullptr && root->right == nullptr)
        {
            if(isLeft)
            {
                return root->val;
            }
        }
        else
        {
            if(root->left != nullptr)
            {
                left = sumOfLeftLeavesHelper(root->left, true);
            }
            if(root->right != nullptr)
            {
                right = sumOfLeftLeavesHelper(root->right , false);
            }
            return left + right;
        }
        return 0;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return sumOfLeftLeavesHelper(root, false);
    }
};