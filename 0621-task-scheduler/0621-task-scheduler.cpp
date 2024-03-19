class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0) return tasks.size();
        vector<int>v(26);
        for(auto it: tasks){
            v[it-'A']++;
        }
        sort(v.begin(),v.end(),greater<int>());
        int idle_slots=(v[0]-1)*n;
        for(int i=1;i<26;i++){
            if(v[i]==0) break;
            idle_slots-=min(v[i],v[0]-1);
        }
        return idle_slots>0?(idle_slots+tasks.size()):tasks.size();
    }
};