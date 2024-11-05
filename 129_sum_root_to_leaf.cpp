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
    void find_path(TreeNode* root, int& sum, int curr)
    {
        if (!root) {
            return;
        }
        
        curr = curr*10 + root->val;
        
        if (!root->left && !root->right) 
        {
            sum += curr;
        }
        else 
        {
            find_path(root->left, sum, curr);
            find_path(root->right, sum, curr);
        }
        //cout<<sum<<"\t"<<curr<<endl;
        curr = 0;
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0, curr = 0;
        find_path(root, sum, curr);
        return sum;
    }
};