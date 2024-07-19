class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        int maxCol[50]={};
        vector<int>vec;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                maxCol[i]=max(maxCol[i],mat[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            int min=0, minR=mat[i][0];
            for(int j=0;j<m;j++){
                if(minR > mat[i][j]){
                    min=j;
                    minR=mat[i][j];
                }
            }
            if(minR==maxCol[min]){
                vec.push_back(minR);
            }
        }
        return vec;
        
    }
};