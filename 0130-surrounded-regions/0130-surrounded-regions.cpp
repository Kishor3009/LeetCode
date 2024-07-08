class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& vis, 
             vector<vector<char>>& mat, int drow[], int dcol[]) {
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < 4; i++) {
            int nr = row + drow[i];
            int nc = col + dcol[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m 
                && !vis[nr][nc] && mat[nr][nc] == 'O')           {
                dfs(nr, nc, vis, mat, drow, dcol);
            }
        }
 
    }
    void solve(vector<vector<char>>& mat) {
        if (mat.empty()) return;
        int n = mat.size();
        int m = mat[0].size();
        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};
        vector<vector<int>> vis(n, vector<int>(m, 0));
    
        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && mat[0][j] == 'O') dfs(0, j, vis, mat, drow, dcol);
            if (!vis[n-1][j] && mat[n-1][j] == 'O') dfs(n-1, j, vis, mat, drow, dcol);
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && mat[i][0] == 'O') dfs(i, 0, vis, mat, drow, dcol);
            if (!vis[i][m-1] && mat[i][m-1] == 'O') dfs(i, m-1, vis, mat, drow, dcol);
        }
    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && mat[i][j] == 'O') mat[i][j] = 'X';
            }
        }
    }
};