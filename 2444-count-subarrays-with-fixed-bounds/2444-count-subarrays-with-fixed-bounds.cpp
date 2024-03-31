class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        long long ans=0;
        int minkp=-1;
        int maxkp=-1;
        int ci=-1;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minK || nums[i]>maxK){
                ci=i;
            }
            if(nums[i]==minK) minkp=i;
            if(nums[i]==maxK) maxkp=i;
            long long smaller=min(minkp,maxkp);
            long long temp=smaller-ci;
            ans+=(temp<=0)?0:temp;
        }
        return ans;
    }
};