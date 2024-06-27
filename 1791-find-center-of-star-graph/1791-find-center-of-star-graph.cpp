class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> nodeCount;
        int edgeCount = edges.size();

        for (const auto& edge : edges) {
            for (const auto& node : edge) {
                nodeCount[node]++;
            }
        }

        vector<int> commonNodes;
        for (const auto& node : nodeCount) {
            if (node.second == edgeCount) {
                commonNodes.push_back(node.first);
            }
        }

        return commonNodes[0];
    }
};