class Solution {
public:
    void FloydWarshall(vector<vector<long long>>&adjmat, vector<char>& original,
                          vector<char>& changed, vector<int>& cost){
        
        for(int i=0;i<original.size();i++){
            int s=original[i]-'a';
            int t=changed[i]-'a';
            adjmat[s][t]=min(adjmat[s][t],(long long)cost[i]);
        }
        
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    adjmat[i][j]=min(adjmat[i][j], adjmat[i][k]+adjmat[k][j]);
                }
            }
        }
    }
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        
        vector<vector<long long>>adjmat(26,vector<long long>(26,INT_MAX));
        FloydWarshall(adjmat, original, changed, cost);
        long long ans=0;
        for(int i=0;i<source.size();i++){
            if(source[i]==target[i]) continue;
            if(adjmat[source[i]-'a'][target[i]-'a']==INT_MAX) return -1;
            ans+=adjmat[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};