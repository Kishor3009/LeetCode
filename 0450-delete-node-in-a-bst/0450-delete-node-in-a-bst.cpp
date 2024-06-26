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
    void inorderTra(TreeNode* root, int key, vector<int>&inorder){
        if(!root) return;
        inorderTra(root->left,key,inorder);
        if(root->val!=key) inorder.push_back(root->val);
        inorderTra(root->right,key,inorder);
    }
    TreeNode* makeTree(int s, int e, vector<int>& inorder) {
        if (s > e) return NULL;

        int m = s + (e - s) / 2;
        TreeNode* d = new TreeNode(inorder[m]);
        d->left = makeTree(s, m - 1, inorder);
        d->right = makeTree(m + 1, e, inorder);
        return d;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        vector<int>inorder;
        inorderTra(root,key,inorder);
        if (inorder.size() == 0) return NULL;

        return makeTree(0, inorder.size() - 1, inorder);
    }
};