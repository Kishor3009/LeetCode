class Solution {
public:
    bool check(int x, vector<int>&a, int m){
        int mp=1, lp=a[0];
        for(int i=1;i<a.size();i++){
            if(a[i]-lp>=x){
                if(++mp==m) return true;
                lp=a[i];
            }
        }
        return false;
    }
    int maxDistance(vector<int>& p, int m) {
        sort(p.begin(),p.end());
        long long low=1, high=*max_element(p.begin(),p.end()), mid, ans=0;
        while(high>=low){
            mid=(low+high)/2;
            if(check(mid,p,m)){
                low=mid+1;
                ans=mid;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};