class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int n=nums1.size();
        int m=nums2.size();
        int k=0;
        int t=0;
        for(int i=0;i<n;i++){
            k=0;
            for(int j=0;j<m;j++){
                if(nums2[j]==nums1[i]){
                    k=j;
                    break;
                }
            }
            t=-1;
            for(int z=k+1;z<m;z++){
                if(nums2[z]>nums1[i]){
                    t=nums2[z];
                    break;
                }
                
            }
            ans.push_back(t);
        }
        return ans;
    }
};