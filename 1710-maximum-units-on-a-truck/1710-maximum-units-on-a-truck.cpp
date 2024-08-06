class Solution {
public:

    int maximumUnits(vector<vector<int>>& boxTypes, int t) {
        sort(boxTypes.begin(), boxTypes.end(), 
             [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];  
        });
        int ans=0;
        int tot=0;
        int n=boxTypes.size();
        for(int i=0;i<n;i++){
            tot+=boxTypes[i][0];
            if(tot>t){
                tot-=boxTypes[i][0];
                ans+=(t-tot)*boxTypes[i][1];
                break;
            }
            else{
                ans+=boxTypes[i][0]*boxTypes[i][1];
            }
        }
        return ans;
    }
};