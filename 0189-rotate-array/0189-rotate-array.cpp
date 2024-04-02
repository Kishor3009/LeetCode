class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector <int>temp(nums.size());
        for(int i=0;i<nums.size();i++){
            temp[(i+k)%(nums.size())]=nums[i];
        }
            nums=temp;
    }
};