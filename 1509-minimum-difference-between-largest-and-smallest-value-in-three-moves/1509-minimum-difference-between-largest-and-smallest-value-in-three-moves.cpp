class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<=3) return 0;
        sort(nums.begin(),nums.end());
        int ans = nums.back() - nums[0];
        for(int i = 0; i <= 3; i++) {
            ans = min(ans, nums[nums.size() - (3 - i) - 1] - nums[i]);
        }
        return ans;
    }
};