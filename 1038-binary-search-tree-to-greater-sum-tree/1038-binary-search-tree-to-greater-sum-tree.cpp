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
    int s=0;
    void rightOrder(TreeNode* &root){
        
        if(root){
            rightOrder(root->right);
            s+=root->val;
            root->val=s;
            rightOrder(root->left);
        }
        
    }
    TreeNode* bstToGst(TreeNode* root) {
        
        rightOrder(root);
        return root;
    }
};