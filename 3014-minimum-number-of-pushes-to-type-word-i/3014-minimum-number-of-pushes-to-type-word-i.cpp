class Solution {
public:
    int minimumPushes(string word) {
        int res=0;
        unordered_map<int,int>mp;
        int assign_val=2;
        for(auto &ch:word){
            if(assign_val >9) assign_val=2;
            
            mp[assign_val]++;
            res+=mp[assign_val];
            assign_val++;
        }
        return res;
    }
};