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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, vector<pair<int, int>>> mp; // horizontal distance -> (level, value)
    vector<vector<int>> ans;
    queue<pair<TreeNode*, pair<int, int>>> q;
    
    q.push({root, {0, 0}});
    int mini = INT_MAX;
    int maxi = INT_MIN;
    
    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        TreeNode* t = it.first;
        int lvl = it.second.first;
        int hd = it.second.second;
        
        mp[hd].push_back({lvl, t->val});
        mini = min(mini, hd);
        maxi = max(maxi, hd);
        
        if (t->left) q.push({t->left, {lvl + 1, hd - 1}});
        if (t->right) q.push({t->right, {lvl + 1, hd + 1}});
    }
    
    for (int i = mini; i <= maxi; ++i) {
        vector<pair<int, int>>& nodes = mp[i];
        sort(nodes.begin(), nodes.end());
        vector<int> col;
        for (auto& p : nodes) {
            col.push_back(p.second);
        }
        ans.push_back(col);
    }
    
    return ans;
}
};