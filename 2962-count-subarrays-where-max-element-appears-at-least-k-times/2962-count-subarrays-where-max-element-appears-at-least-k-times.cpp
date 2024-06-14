class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxEle=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxEle=max(maxEle,nums[i]);
        }
        long long s=0,e=0,maxFreq=0,c=0;
        int n=nums.size();
        while(e<n){
            if(nums[e]==maxEle){
                maxFreq++;
            }
            while(maxFreq==k){
                c+=(n-e);
                if(nums[s]==maxEle) {
                    maxFreq--;
                }
                s++;
            }
            e++;
        }
        return c;
        
        
    }
};