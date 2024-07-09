class Solution {
public:
    bool search(vector<int>& arr, int k) {
        int n=arr.size();
        int l=0,h=n-1;
        while(l<=h){
            int m=l+(h-l)/2;
            if(arr[m]==k) return true;
            if(arr[l]==arr[m] && arr[m]==arr[h]){
                l++;
                h--;
                continue;
            }
            else if(arr[l]<=arr[m]){
                if(arr[l]<=k && k<=arr[m]) h=m-1;
                else l=m+1;
            }
            else{
                if(arr[m]<=k && k<=arr[h]) l=m+1;
                else h=m-1;
            }
        }
        return false;
    }
};