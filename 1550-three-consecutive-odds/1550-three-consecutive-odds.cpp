class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();
        int c=0;
        for(int i=0;i<n;i++){
            if(arr[i]%2==1){
                c++;
                if(c==3) return true;
            }
            else c=0;
        }
        return false;
    }
};