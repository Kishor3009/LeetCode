class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<string>str;
        unordered_map<string,int>mpp;
        int i=0;
        for(auto it: list1){
            mpp[it]=i;
            i++;
        }
        i=0;
        unordered_map<string,int>m;
        for(auto it:list2){
            if(mpp.find(it)!=mpp.end()){
                m[it]=mpp[it]+i;
                
            }
            i++;
        }
        int mini=10000;
        for(auto it:m){
            if(it.second<=mini){
                mini=min(it.second,mini);
            }
        }
        for(auto it:m){
            if(it.second==mini){
                str.push_back(it.first);
            }
        }
        
        return str;
    }
};