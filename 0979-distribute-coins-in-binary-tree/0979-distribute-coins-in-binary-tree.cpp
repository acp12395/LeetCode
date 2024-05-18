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
    int distributeCoinsHelper(TreeNode* root, int& spare)
    {
        int movesL = 0, movesR = 0, spareL, spareR;
        if(root->left)
        {
            movesL = distributeCoinsHelper(root->left, spareL);
        }
        if(root->right)
        {
            movesR = distributeCoinsHelper(root->right, spareR);
        }
        spare = root->val - 1;
        spare += spareL + spareR;
        return movesL + movesR + abs(spare);
    }
public:
    int distributeCoins(TreeNode* root) {
        int noSpare = 0;
        return distributeCoinsHelper(root, noSpare);
    }
};