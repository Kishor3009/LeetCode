class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return (a.second == b.second) ? a.first > b.first : a.second < b.second;
    }

    vector<int> frequencySort(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        vector<pair<int, int>> val;
        for (auto it : mp) {
            val.push_back(it);
        }
        sort(val.begin(),val.end(),cmp);
        vector<int>res;
        for(auto it:val){
            for(int i=0;i<it.second;i++){
                res.push_back(it.first);
            }
        }
        return res;
    }
};