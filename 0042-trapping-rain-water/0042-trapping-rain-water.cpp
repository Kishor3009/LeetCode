class Solution {
public:
    int trap(vector<int>& height) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = height.size();
        if (n == 0) return 0; 
        vector<int> left(n), right(n);
        
        left[0] = height[0];
        for (int i = 1; i < n; ++i) {
            left[i] = max(left[i - 1], height[i]);
        }
        
        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            right[i] = max(right[i + 1], height[i]);
        }
        
        int totalWater = 0;
        for (int i = 0; i < n; ++i) {
            int minHeight = min(left[i], right[i]);
            totalWater += max(0, minHeight - height[i]); 
        }
        
        return totalWater;
    }
};