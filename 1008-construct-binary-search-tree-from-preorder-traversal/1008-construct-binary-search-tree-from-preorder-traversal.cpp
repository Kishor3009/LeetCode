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
    TreeNode* makeTree(int &index, int upperBound, vector<int>& preorder) {
        if (index == preorder.size() || preorder[index] > upperBound) {
            return NULL;
        }
    
        TreeNode* root = new TreeNode(preorder[index++]);
        root->left = makeTree(index, root->val, preorder);
        root->right = makeTree(index, upperBound, preorder);
    
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        return makeTree(index,INT_MAX,preorder);
    }
};