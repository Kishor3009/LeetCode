class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<int, int> mpp;
        for (int num : nums) {
            if (mpp[num] >= 1) {
                return true; 
            } else {
                mpp[num]++;
            }
        }
        return false; 
    }
};