class Solution {
public:
    bool canJump(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // int n = nums.size();
        // int lastPos = n - 1; 
        // for (int i = n - 2; i >= 0; i--) {
        //     if (i + nums[i] >= lastPos) {
        //         lastPos = i;
        //     }
        // }
        // return lastPos == 0;
        
        int maxind=0;
        for(int i=0;i<nums.size();i++){
            if(i>maxind) return false;
            maxind=max(maxind,nums[i]+i);
        }
        return true;
    }

};