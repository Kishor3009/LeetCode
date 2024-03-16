class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int s=0;
        int long_sub=0;
        for(int i=0;i<nums.size();i++){
            s+=nums[i]==0?-1:1;
            if(s==0){
                if(long_sub<i+1){
                    long_sub=i+1;
                }
            }
            else if(mpp.find(s)!=mpp.end()){
                if(long_sub<i-mpp[s]){
                    long_sub=i-mpp[s];
                }
            }
            else{
                mpp[s]=i;
            }
        }
        return long_sub;
    }
};