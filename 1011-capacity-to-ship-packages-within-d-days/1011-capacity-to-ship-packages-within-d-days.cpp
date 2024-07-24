class Solution {
public:
    int findDays(vector<int>& w,int cap){
        int d=1,load=0;
        for(int i=0;i<w.size();i++){
            if(w[i]+load > cap){
                d+=1;
                load=w[i];
            }
            else{
                load+=w[i];
            }
        }
        return d;
    }
    int shipWithinDays(vector<int>& w, int days) {
        int l=*max_element(w.begin(),w.end());
        int h=accumulate(w.begin(),w.end(),0);
        while(l<=h){
            int mid=(l+h)/2;
            if(findDays(w,mid)<=days){
                h=mid-1;
            }
            else l=mid+1;
        }
        return l;
    }
};