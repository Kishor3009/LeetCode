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
    TreeNode* insertIntoBST(TreeNode* root, int v) {
        TreeNode* t=root;
        
        if(root==NULL){
            return new TreeNode(v);
        }
        while(true){
            if(v > t->val){
                if(t->right!=NULL){
                    t=t->right;
                }
                else{
                    t->right=new TreeNode(v);
                    break;
                }
            }
            else{
                if(t->left!=NULL){
                    t=t->left;
                }
                else{
                    t->left=new TreeNode(v);
                    break;
                }
            }
        }
        return root;
    }
};