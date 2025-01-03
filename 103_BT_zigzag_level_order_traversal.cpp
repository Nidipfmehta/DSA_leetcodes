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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int c=0;
        if (root == NULL)
        {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int level_nodes = q.size();
            vector<int> curr_level;
            for(int i=0; i<level_nodes; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                curr_level.push_back(node->val);
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            if (c%2==1)
            {
                reverse(curr_level.begin(), curr_level.end());
            }
            c++;
            ans.push_back(curr_level);
        }
        return ans;
    
    }
};