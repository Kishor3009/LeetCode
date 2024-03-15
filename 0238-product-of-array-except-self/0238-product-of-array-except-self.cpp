class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        int z=0;
        int p=1;
        for(auto num:nums){
            if(num==0){
                z++;
                continue;
            }
            p*=num;
        }
        if(z==1){
            for(int i=0;i<n;i++){
                ans[i]=nums[i]==0 ?p:0;
            }
        }
        else if(z==0){
            for(int i=0;i<n;i++){
                ans[i]=p/nums[i];
            }
        }
        return ans;
    }
};