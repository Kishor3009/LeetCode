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
    void traversal(TreeNode* root,int &c){
        if(root==NULL) return;
        c++;
        traversal(root->left,c);
        traversal(root->right,c);
    }
    int countNodes(TreeNode* root) {
        int c=0;
        traversal(root,c);
        return c;
    }
};