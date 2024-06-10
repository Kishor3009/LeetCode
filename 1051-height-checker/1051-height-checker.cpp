class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n=heights.size();
        vector<int>arr=heights;
        int c=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(arr[i]!=heights[i]) c++;
        }
        return c;
    }
};