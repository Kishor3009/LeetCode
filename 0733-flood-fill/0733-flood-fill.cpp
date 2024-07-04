class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& image,
             vector<vector<int>>& ans, int newcol,int nrow[], int ncol[], int inicolor){
        ans[row][col]=newcol;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int r=row+nrow[i];
            int c=col+ncol[i];
            if(r>=0 && r<n && c>=0 && c<m 
              && image[r][c]==inicolor && ans[r][c]!=newcol){
                dfs(r,c,image,ans,newcol,nrow,ncol,inicolor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor=image[sr][sc];
        vector<vector<int>>ans= image;
        int nrow[]={1,0,-1,0};
        int ncol[]={0,1,0,-1};
        dfs(sr,sc,image,ans,color,nrow,ncol,inicolor);
        return ans;
    }
};