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

TreeNode* solve(vector<int>& in, vector<int>& pre, int& index, int start, int end, map<int, int>& nodeToInd) {
    if (index >= pre.size() || start > end) {
        return NULL;
    }

    int e = pre[index++];
    TreeNode* node = new TreeNode(e);
    int pos = nodeToInd[e];

    node->left = solve(in, pre, index, start, pos - 1, nodeToInd);
    node->right = solve(in, pre, index, pos + 1, end, nodeToInd);
    return node;
}

TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
    int pi = 0;
    map<int, int> nodeToInd;
    createMapping(in, nodeToInd);
    return solve(in, pre, pi, 0, in.size() - 1, nodeToInd);
}
};