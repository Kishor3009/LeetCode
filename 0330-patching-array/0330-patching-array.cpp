class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int m=nums.size();
        int tp=0;
        int i=0;
        long long sum=1;
        while(sum<=n){
            sum+=(i<nums.size() && nums[i]<=sum)?nums[i++]:sum;
            tp++;
        }
        return tp-i;
    }
};