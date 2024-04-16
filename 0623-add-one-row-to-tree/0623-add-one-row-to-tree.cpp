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
    TreeNode* addOneRowHelper(TreeNode* root, int& val, int& depth, int& currDepth)
    {
        if(currDepth == depth - 1)
        {
            TreeNode* prevLeftNode = new TreeNode(val, nullptr, nullptr);
            TreeNode* prevRightNode = new TreeNode(val, nullptr, nullptr);
            if(root->left)
            {
                prevLeftNode->left = root->left;
            }
            root->left = prevLeftNode;
            if(root->right)
            {
                prevRightNode->right = root->right;
            }
            root->right = prevRightNode;
        }
        else
        {
            if(root->left)
            {
                addOneRowHelper(root->left,val,depth,++currDepth);
                currDepth--;
            }
            if(root->right)
            {
                addOneRowHelper(root->right,val,depth,++currDepth);
                currDepth--;
            }
        }
        return root;
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1)
        {
            TreeNode* prevNode = new TreeNode(val, root, nullptr);
            return prevNode;
        }
        else
        {
            int currDepth = 1;
            return addOneRowHelper(root,val,depth,currDepth);
        }
    }
};