class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
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