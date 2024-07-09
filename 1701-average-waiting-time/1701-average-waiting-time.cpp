class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& cust) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        double s=0,tot=0;
        double d=0;
        double n=cust.size();
        tot=cust[0][1];
        s=cust[0][0]+cust[0][1];
        for(int i=1;i<n;i++){
            if(s>=cust[i][0]){
                s+=cust[i][1];
            }
            else{
                s=cust[i][0]+cust[i][1];
            }
            tot+=s-cust[i][0];
        }
        d=tot/n;
        return d;
    }
};