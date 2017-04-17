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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        if (!root) return res;
        
        queue<TreeNode*> Q;
        Q.push(root);
        
        TreeNode* node;
        while (!Q.empty()) {
            node = Q.front();
            Q.pop();
            
            if (node) {
                res += to_string(node->val);
                Q.push(node->left);
                Q.push(node->right);
            }
            else
                res += "null";
            
            res += ",";
        }
        
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        
        int pos = data.find_first_of(',', 0);
        TreeNode* root = new TreeNode(stoi(data.substr(0, pos)));
        
        int head = pos + 1;
        
        queue<TreeNode*> Q;
        Q.push(root);
        
        string val;
        
        while (head < data.size() && !Q.empty()) {
            TreeNode* current = Q.front();
            Q.pop();

            pos = data.find_first_of(',', head);
            val = data.substr(head, pos - head);
            head = pos + 1;
            
            current->left = (val != "null") ? new TreeNode(stoi(val)) : NULL;
                
            pos = data.find_first_of(',', head);
            val = data.substr(head, pos - head);
            head = pos + 1;
            
            current->right = (val != "null") ? new TreeNode(stoi(val)) : NULL;
            
            if (current->left) Q.push(current->left);
            if (current->right) Q.push(current->right);
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
