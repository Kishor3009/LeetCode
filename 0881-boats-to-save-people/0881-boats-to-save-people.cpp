class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=p.size();
        int high=n-1;
        int l=0;
        int c=0;
        sort(p.begin(),p.end());
        while(high>=l){
            int curr=p[high];
            if(p[l]+curr<=limit){
                l++;
                c++;
                high--;
            }
            else{
                high--;
                c++;
            }
        }
        return c;
    }
};