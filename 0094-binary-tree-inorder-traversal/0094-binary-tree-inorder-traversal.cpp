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
    vector<int> inorderTraversal(TreeNode* root) {
        // vector<int>vec;
        // stack <TreeNode*> stk;
        // while(true){
        //     if(root!=nullptr){
        //         stk.push(root);
        //         root=root->left;
        //     }
        //     else{
        //         if(stk.empty()) break;
        //         root=stk.top();
        //         vec.push_back(root->val);
        //         stk.pop();
        //         root=root->right;
        //     }
        // }
        // return vec;
        
        vector<int>inorder;
        TreeNode* curr=root;
        while(curr){
            if(!curr->left){
                inorder.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* prev=curr->left;
                while(prev->right && prev->right!=curr) prev=prev->right;
                if(!prev->right){
                    prev->right=curr;
                    
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    inorder.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return inorder;
    }
};