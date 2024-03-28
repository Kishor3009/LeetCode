class Solution {
public:
    bool canJump(vector<int>& nums) {
    int n = nums.size();
    int lastPos = n - 1; // The last position we need to reach
    
    // Start from the last second position and update lastPos if we can reach it
    for (int i = n - 2; i >= 0; i--) {
        if (i + nums[i] >= lastPos) {
            lastPos = i;
        }
    }
    
    // If lastPos is the first position, it means we can reach the last index
    return lastPos == 0;
}

};