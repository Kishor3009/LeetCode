class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int c=0;
        int ps=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int num:nums){
            ps+=num;
            int mod=ps%k;
            if(mod<0){
                mod+=k;
            }
            if(mp.find(mod)!=mp.end()){
                c+=mp[mod];
                mp[mod]+=1;
            }
            else{
                mp[mod]=1;
            }
        }
        
        return c;
    }
};