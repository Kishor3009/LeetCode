class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>vec;
        int i=0, f=0;
        int j=0, k=n-1;
        while(i<n){
            if(f==0){
                vec.push_back(nums[k]);
                k--;
                f=1;
            }
            else{
                f=0;
                vec.push_back(nums[j]);
                j++;
            }
            i++;
        }
        return vec;
    }
};