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
    vector<int> root1Vector;
    vector<int> root2Vector;
    void leafSimilarHelper(TreeNode* root, vector<int>& vector)
    {
        if(root->left == nullptr && root->right == nullptr)
        {
            vector.push_back(root->val);
        }
        else
        {
            if(root->left != nullptr)
            {
                leafSimilarHelper(root->left, vector);
            }
            if(root->right != nullptr)
            {
                leafSimilarHelper(root->right, vector);
            }
        }
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        bool retVal;
        leafSimilarHelper(root1, root1Vector);
        leafSimilarHelper(root2, root2Vector);
        retVal = (root1Vector == root2Vector) ? true : false;
        root1Vector.clear();
        root2Vector.clear();
        return retVal;
    }
};