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
    vector<pair<int,int>> sumNumbersHelper(TreeNode* root)
    {
        vector<pair<int, int>> storageVec;
        if(root->left == nullptr && root->right == nullptr)
        {
            storageVec.push_back({root->val,0});
        }
        else
        {
            if(root->left)
            {
                vector<pair<int,int>> leftVec = sumNumbersHelper(root->left);
                storageVec.insert(storageVec.end(), leftVec.begin(), leftVec.end());
            }
            if(root->right)
            {
                vector<pair<int,int>> rightVec = sumNumbersHelper(root->right);
                storageVec.insert(storageVec.end(), rightVec.begin(), rightVec.end());
            }
            for(auto& [number, power] : storageVec)
            {
                number = number + (root->val * pow(10,++power));
            }
        }
        return storageVec;
    }
public:
    int sumNumbers(TreeNode* root) {
        vector<pair<int,int>> numbersStorage = sumNumbersHelper(root);
        int sum = 0;
        for(auto& [number,_] : numbersStorage)
        {
            sum += number;
        }
        return sum;
    }
};