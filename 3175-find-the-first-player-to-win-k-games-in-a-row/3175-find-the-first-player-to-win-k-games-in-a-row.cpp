class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        deque<pair<int,pair<int,int>>> dq;
        for(int i=0;i<skills.size();i++){
            dq.push_back({i,{skills[i],0}});
        }
        int n=skills.size();
        if(k>=n){
            int maxi=-1,ans=-1;
            for(int i=0;i<skills.size();i++){
                if(skills[i]>maxi){
                    maxi=skills[i];
                    ans=i;
                }
            }
            return ans;
        }
        while(!dq.empty()){
            auto p1=dq.front();
            dq.pop_front();
            auto p2=dq.front();
            dq.pop_front();
            if(p1.second.first>p2.second.first){
                p1.second.second=p1.second.second+1;
                if(p1.second.second==k) return p1.first;
                dq.push_front(p1);
                dq.push_back(p2);
            }
            else{
                p2.second.second=p2.second.second+1;
                if(p2.second.second==k) return p2.first;
                dq.push_front(p2);
                dq.push_back(p1);
            }
        }
        return 0;
    }
};