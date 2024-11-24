/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void serializeHelper(TreeNode* root, string &s1) {
        if(!root) {
            s1 += "n ";
            return;
        }
        s1 += to_string(root->val) + " ";
        serializeHelper(root->left, s1);
        serializeHelper(root->right, s1);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s1 = "";
        serializeHelper(root, s1);
        return s1;
    }
        

    TreeNode* deserializeHelper(string &data, int &i) {
        if(i >= data.size()) {
            return NULL;
        }
        int spacePos = data.find(' ', i);
        string token = data.substr(i, spacePos - i);
        i = spacePos + 1;
        if (token == "n") {
            return NULL;
        }
        TreeNode* newnode = new TreeNode(stoi(token)); 
        newnode->left = deserializeHelper(data, i);
        newnode->right = deserializeHelper(data, i);
        return newnode;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i=0;
        return deserializeHelper(data, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));