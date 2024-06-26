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
    TreeNode* mid(vector<int>&v, int s, int e){
        if(s>e) return NULL;
        int m=s+(e-s)/2;
        TreeNode* root=new TreeNode(v[m]);
        root->left=mid(v,s,m-1);
        root->right=mid(v,m+1,e);
        return root;
    }
    void inorder(TreeNode* root,vector<int>&v){
        if(root==NULL) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v;
        inorder(root,v);
        int n=v.size()-1;
        return mid(v,0,n);
    }
};