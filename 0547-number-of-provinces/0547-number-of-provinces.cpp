class Solution {
public:
    void dfs(int visited[], unordered_map<int,list<int>>&adj, int node){
        visited[node]=1;
        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(visited,adj,it);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int, list<int>> adj;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int visited[n];
        memset(visited, 0, sizeof(visited));
        int c=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                c++;
                dfs(visited,adj,i);
            }
        }
        return c;
    }
};