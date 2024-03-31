class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=arr.size();
        int maxi=-1,tmp;
        for(int i=n-1;i>=0;i--){
            tmp=arr[i];
            arr[i]=maxi;
            maxi=max(maxi,tmp);
        }
        return arr;
    }
};