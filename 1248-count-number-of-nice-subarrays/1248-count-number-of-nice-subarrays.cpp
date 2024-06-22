class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int oc=0, c=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==1) oc++;
            if(oc==k) c++;
            if(mp.find(oc-k)!=mp.end()) c+=mp[oc-k];
            if(mp.find(oc)!=mp.end()) mp[oc]++;
            else mp[oc]=1;
        }
        return c;
    }
};