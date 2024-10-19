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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> hash;
        vector<vector<int>> ans;
        vertical_traversal_recur(hash, root, 0, 0);
        for(auto it1 = hash.begin(); it1!=hash.end(); it1++)
        {
            vector<int> inner;
            //cout<<"column : "<<it1->first<<endl;
            for(auto it2 = (it1->second).begin(); it2!=(it1->second).end() ;it2++)
            {
                sort(it2->second.begin(), it2->second.end());
                // inner.push_back(it2->second);
                // cout<<"row : "<<it2->first<<endl;
                for(auto it3 = (it2->second).begin(); it3!=(it2->second).end() ;it3++)
                {
                    // cout<<*it3<<"  ";
                    inner.push_back(*it3);
                }
                //cout<<"\n";
            }
            ans.push_back(inner);
        }
        return ans;
    }

    void vertical_traversal_recur(map<int, map<int, vector<int>>>& hash, TreeNode* root, int r, int c)
    {
        if (root == NULL)
        {
            return;
        }
        hash[c][r].push_back(root->val);
        vertical_traversal_recur(hash, root->left, r+1, c-1);
        vertical_traversal_recur(hash, root->right, r+1, c+1);
    }
};