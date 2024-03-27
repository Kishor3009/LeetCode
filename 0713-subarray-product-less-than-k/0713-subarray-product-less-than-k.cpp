class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(k<=1) return 0;
        int prod=1;
        int res=0;
        int l=0,r=0;
        while(r<nums.size()){
            prod*=nums[r];
            while(prod>=k){
                prod/=nums[l];
                l++;
            }
            res+=r-l+1;
            r++;
        }
        return res;
    }
};