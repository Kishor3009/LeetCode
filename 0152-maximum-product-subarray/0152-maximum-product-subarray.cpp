class Solution {
public:
    int maxProduct(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    int pre = 1, suf = 1;
    int ans = INT_MIN;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        pre *= nums[i];
        suf *= nums[n - 1 - i];
        ans = max(ans, max(pre, suf));
        if (pre == 0) pre = 1;
        if (suf == 0) suf = 1;
    }
    return ans;  
}

};