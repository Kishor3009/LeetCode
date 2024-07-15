class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if (grid[0][0] == 1 || grid[n-1][m-1] == 1) {
            return -1;
        }
        if(0==n-1 && 0==m-1) return 1;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        queue<pair<int,pair<int,int>>>q;
        dist[0][0]=1;
        q.push({1,{0,0}});
        int drow[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        int dcol[] = {0, 0, -1, 1, -1, 1, -1, 1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int d=it.first;
            int r=it.second.first;
            int c=it.second.second;
            for(int i=0;i<8;i++){
                int row=r+drow[i];
                int col=c+dcol[i];
                if(row>=0 && row<n && col>=0 && col<n 
                   && grid[row][col]==0 && d+1 < dist[row][col]){
                    dist[row][col]=d+1;
                    if(row==n-1 && col==m-1) return d+1;
                    q.push({d+1,{row,col}});
                }
            }
        }
        return -1;
    }
};