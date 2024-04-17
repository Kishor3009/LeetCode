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
    string result;
    void solve(TreeNode* root, string str){
        if(root->left==NULL && root->right==NULL){
            str+=(root->val+'a');
            reverse(str.begin(),str.end());
            if(str.length()>0 && str<result){
                result=str;
            }
            reverse(str.begin(),str.end());
            return;
        }
        str+=(root->val+'a');
        if(root->left) solve(root->left,str);
        if(root->right) solve(root->right,str);
    }
    string smallestFromLeaf(TreeNode* root) {
        result=string(1,'z'+1);
        solve(root,"");
        return result;
    }
};