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
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> retVal;
        TreeNode* treeIt = root;
        vector<TreeNode*> pointersStorageVector;
        vector<TreeNode*> leftPointersStorageVector;
        bool leftStep = false;

        if(treeIt != nullptr)
        {
            while(1)
            {
                while(treeIt->left)
                {
                    pointersStorageVector.push_back(treeIt);
                    leftPointersStorageVector.push_back(treeIt);
                    treeIt = treeIt->left;
                }
                retVal.push_back(treeIt->val);
                while(treeIt->right == nullptr)
                {
                    do
                    {
                        if(treeIt != root && !leftPointersStorageVector.empty())
                        {
                            if(leftPointersStorageVector.back() == pointersStorageVector.back())
                            {
                                leftPointersStorageVector.pop_back();
                                leftStep = true;
                            }
                            else
                            {
                                leftStep = false;
                            }
                            treeIt = pointersStorageVector.back();
                            pointersStorageVector.pop_back();
                            
                        }
                        else
                        {
                            return retVal;
                        }
                    } while (!leftStep);
                    retVal.push_back(treeIt->val);
                }
                pointersStorageVector.push_back(treeIt);
                treeIt = treeIt->right;
            }
        }
        return retVal;
    }
};