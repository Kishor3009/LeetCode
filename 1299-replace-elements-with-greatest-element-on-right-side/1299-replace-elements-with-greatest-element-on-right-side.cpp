class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=arr.size();
        int maxi=INT_MIN;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                maxi=max(maxi,arr[j]);
            }
            arr[i]=maxi;
            maxi=INT_MIN;
        }
        arr[n-1]=-1;
        return arr;
    }
};