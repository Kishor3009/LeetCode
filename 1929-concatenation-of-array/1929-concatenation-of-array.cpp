class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int>vec;
        for(auto it: nums){
            vec.push_back(it);
        }
        for(auto it:nums){
            vec.push_back(it);
        }
        return vec;
    }
};