class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_set<int> seen;
        for (int i = 0; i < nums.size(); ++i) {
            if (seen.find(nums[i]) != seen.end()) {
                return true; 
            }
            seen.insert(nums[i]); 
            if (seen.size() > k) {
                seen.erase(nums[i - k]); 
            }
        }
        return false; 
    }
};