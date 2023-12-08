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
    string tree2str(TreeNode* root) {
        string retVal;
        retVal.append(to_string(root->val));
        if(root->left != nullptr || root->right != nullptr)
        {
            retVal.push_back('(');
            if(root->left != nullptr)
            {
                retVal.append(tree2str(root->left));
            }
            retVal.push_back(')');
            if(root->right != nullptr)
            {
                retVal.push_back('(');
                retVal.append(tree2str(root->right));
                retVal.push_back(')');
            }
        }
        return retVal;
    }
};