class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& pre) {
        vector<int>adj[N];
	    for(auto it:pre){
	        adj[it[1]].push_back(it[0]);
	    }
	    vector<int> indegree(N,0);
	    for(int i=0;i<N;i++){
	        for(int neighbour:adj[i]){
	            indegree[neighbour]++;
	        }
	    }
	    queue<int>q;
	    for(int i=0;i<N;i++){
	        if(indegree[i]==0) q.push(i);
	    }
	    vector<int>ans;
	    while(!q.empty()){
	        int f=q.front();
	        q.pop();
	        ans.push_back(f);
	        for(int neighbour:adj[f]){
	            indegree[neighbour]--;
	            if(indegree[neighbour]==0){
	                q.push(neighbour);
	            }
	        }
	    }
	    if(ans.size()==N) return ans;
	    return {};
    }
};