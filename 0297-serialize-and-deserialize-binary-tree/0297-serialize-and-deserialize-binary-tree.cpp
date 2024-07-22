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

     string serialize(TreeNode* root) {
        if (!root) return "";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            if (t == NULL) {
                s += "#,";
            } else {
                s += to_string(t->val) + ",";
                q.push(t->left);
                q.push(t->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* t = q.front();
            q.pop();

            // Left child
            getline(s, str, ',');
            if (str == "#") {
                t->left = NULL;
            } else {
                TreeNode* left = new TreeNode(stoi(str));
                t->left = left;
                q.push(left);
            }

            // Right child
            getline(s, str, ',');
            if (str == "#") {
                t->right = NULL;
            } else {
                TreeNode* right = new TreeNode(stoi(str));
                t->right = right;
                q.push(right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));