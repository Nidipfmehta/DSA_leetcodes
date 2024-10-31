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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            int t;
            TreeNode* temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                if(!q.empty())
                {
                    q.push(NULL);
                }
                ans.push_back(t);
            }
            else
            {
                t = temp->val;
                if(temp->left != NULL)
                {
                    q.push(temp->left);
                }
                if (temp->right != NULL)
                {
                    q.push(temp->right);
                }
                
                //cout<<t<<endl;
            }
            
        }
        return ans;
    }
};