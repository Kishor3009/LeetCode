class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (int num : nums) {
            if (mpp[num] >= 1) {
                return true; // Found a duplicate
            } else {
                mpp[num]++;
            }
        }
        return false; // No duplicates found
    }
};