class Solution {
public:
    int sumofd(vector<int>& nums, int div){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=ceil((double)(nums[i]) / (double)(div));
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1, h=*max_element(nums.begin(),nums.end());
        while(l<=h){
            int mid=(l+h)/2;
            if(sumofd(nums,mid)<= threshold){
                h=mid-1;
            }
            else l=mid+1;
        }
        return l;
    }
};