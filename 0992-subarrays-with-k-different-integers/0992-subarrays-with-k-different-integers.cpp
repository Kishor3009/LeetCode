class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostK(nums, k) - atmostK(nums, k - 1);
    }

private:
    int atmostK(vector<int>& nums, int k) {
        int start = 0, ans = 0;
        unordered_map<int, int> mpp;
        for (int end = 0; end < nums.size(); end++) {
            mpp[nums[end]]++;
            while (mpp.size() > k) {
                mpp[nums[start]]--;
                if (mpp[nums[start]] == 0) {
                    mpp.erase(nums[start]);
                }
                start++;
            }
            ans += (end - start + 1);
        }
        return ans;
    }
};
