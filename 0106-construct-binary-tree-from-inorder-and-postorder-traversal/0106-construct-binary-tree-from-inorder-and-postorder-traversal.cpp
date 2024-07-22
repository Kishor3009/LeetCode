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
    void createMapping(vector<int>& in, map<int, int>& nodeToInd) {
        for (int i = 0; i < in.size(); i++) {
            nodeToInd[in[i]] = i;
        }
    }

    TreeNode* solve(vector<int>& in, vector<int>& post, int& index, 
                    int start, int end, map<int, int>& nodeToInd) {
        if (index < 0 || start > end) {
            return NULL;
        }

        int e = post[index--];
        TreeNode* node = new TreeNode(e);
        int pos = nodeToInd[e];
        node->right = solve(in, post, index, pos + 1, end, nodeToInd);
        node->left = solve(in, post, index, start, pos - 1, nodeToInd);
        return node;
    }

    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int pi = post.size() - 1;
        map<int, int> nodeToInd;
        createMapping(in, nodeToInd);
        return solve(in, post, pi, 0, in.size() - 1, nodeToInd);
    }
};