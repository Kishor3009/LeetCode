class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0]; 
    if (nums[0] != nums[1]) return nums[0];
    if (nums[n-2] != nums[n-1]) return nums[n-1]; 

    int l = 0, h = n - 1;

    while (l <= h) {
        int m = l + (h - l) / 2;
        if ((m == 0 || nums[m] != nums[m - 1]) && 
            (m == n - 1 || nums[m] != nums[m + 1])) {
            return nums[m];
        }
        if ((m % 2 == 1 && nums[m] == nums[m - 1]) || 
            (m % 2 == 0 && nums[m] == nums[m + 1]))         {
            l = m + 1;
        } else {
            h = m - 1;
        }
    }

    return -1;
}

};