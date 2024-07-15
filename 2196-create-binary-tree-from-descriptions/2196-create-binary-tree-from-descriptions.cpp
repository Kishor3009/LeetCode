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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        unordered_map<int,TreeNode*>mpp;
        unordered_set<int>chil;
        
        for(auto arr:desc){
            int par=arr[0],child=arr[1],isL=arr[2];
            chil.insert(child);
            if(mpp.find(par)==mpp.end()){
                mpp[par]=new TreeNode(par);
            }
            if(mpp.find(child)==mpp.end()){
                mpp[child]=new TreeNode(child);
            }
            if(isL==1){
                mpp[par]->left=mpp[child];
            }
            else{
                mpp[par]->right=mpp[child];
            }
        }
        int root=-1;
        for(auto &arr: desc){
            if(chil.find(arr[0])==chil.end()){
                root=arr[0];
                break;
            }
        }
        return mpp[root];
    }
};