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
    void find_path(TreeNode* root, vector<vector<int>>& ans, vector<int>& curr, int targetsum)
    {
        if (!root) {
            return;
        }
        
        curr.push_back(root->val);
        targetsum -= root->val;
        
        if (targetsum == 0 && !root->left && !root->right) 
        {
            ans.push_back(curr);
        } 
        else 
        {
            find_path(root->left, ans, curr, targetsum);
            find_path(root->right, ans, curr, targetsum);
        }
        
        curr.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> curr;
        find_path(root, ans, curr, targetSum);
        return ans;
    }
};