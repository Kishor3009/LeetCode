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
    TreeNode* lcap(TreeNode* root, int s,int d){
        if(!root) return NULL;
        if(root->val==s || root->val==d) return root;
        auto left=lcap(root->left,s,d);
        auto right=lcap(root->right,s,d);
        if(left && right) return root;
        if(!left && !right) return NULL;
        return left?left:right;
    }
    bool dfs(TreeNode* root, int t,string & path){
        if(root==NULL) return false;
        if(root->val==t) return true;
        path+='L';
        if(dfs(root->left,t,path)) return true;
        path.pop_back();
        path+='R';
        if(dfs(root->right,t,path)) return true;
        path.pop_back();
        return false;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        auto lca=lcap(root,startValue,destValue);
        string p1="",p2="";
        dfs(lca,startValue,p1);
        for(auto &i:p1){
            i='U';
        }
        dfs(lca,destValue,p2);
        return p1+p2;
    }
};