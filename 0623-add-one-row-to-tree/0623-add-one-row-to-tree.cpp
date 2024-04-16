class Solution {
public:
    void insert(TreeNode* node, int d, int v, int currd) {
        if (node == NULL) return;
        if (currd == d - 1) {
            TreeNode* temp = node->left;
            node->left = new TreeNode(v);
            node->left->left = temp;
            temp = node->right;
            node->right = new TreeNode(v);
            node->right->right = temp;
        } else {
            insert(node->left, d, v, currd + 1);
            insert(node->right, d, v, currd + 1);
        }
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        insert(root, depth, val, 1);
        return root;
    }
};
