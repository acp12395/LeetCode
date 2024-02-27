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
    void diameterOfBinaryTreeHelper(TreeNode* root, vector<int>& helperVec)
    {
        int left = 0, right = 0, sum;
        if(root->left)
        {
            helperVec[1] = 0;
            diameterOfBinaryTreeHelper(root->left, helperVec);
            left = helperVec[1];
        }
        if(root->right)
        {
            helperVec[1] = 0;
            diameterOfBinaryTreeHelper(root->right, helperVec);
            right = helperVec[1];
        }
        sum = left + right;
        helperVec[1] = left > right ? left : right;
        helperVec[0] = helperVec[0] > sum ? helperVec[0] : sum;
        helperVec[1]++;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        vector<int> res(2);
        diameterOfBinaryTreeHelper(root, res);
        return res[0];
    }
};