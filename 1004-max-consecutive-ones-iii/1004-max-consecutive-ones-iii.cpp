class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=0,z=0,maxlen=0;
        while (r < n) {
            if (nums[r] == 0) {
                z++;
            }
            r++;
        
            while (z > k) {
                if (nums[l] == 0) {
                    z--;
                }
                l++;
            }

            maxlen = max(maxlen, r - l);
        }
        return maxlen;
    }
};