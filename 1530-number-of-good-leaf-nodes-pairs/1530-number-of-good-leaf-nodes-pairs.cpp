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
    vector<int>recur(TreeNode* root, int d,int &c){
        if(!root) return {0};
        if(!root->left && !root->right) return {1};
        
        vector<int>l=recur(root->left,d,c);
        vector<int>r=recur(root->right,d,c);
        
        for(int x:l){
            for(int y:r){
                if(x>0 && y>0){
                    if(x+y<= d) c++;   
                }
            }
        }
        vector<int>ans;
        for(int x:l){
            if(x>0 && x<d){
                ans.push_back(x+1);
            }
        }
        for(int x:r){
            if(x>0 && x<d){
                ans.push_back(x+1);
            }
        }
        return ans;
    }
    int countPairs(TreeNode* root, int d) {
        int c=0;
        recur(root,d,c);
        return c;
    }
};