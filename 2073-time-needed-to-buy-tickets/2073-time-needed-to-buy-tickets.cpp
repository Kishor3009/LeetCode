class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=tickets.size();
        int t=0;
        while(tickets[k]>0){
            for(int i=0;i<n;i++){
                if(tickets[i]!=0 && i==k){
                    tickets[i]--;
                    t++;
                }
                else if(tickets[i]!=0 && i!=k){
                    tickets[i]--;
                    t++;
                }
                if(tickets[i]==0 && i==k){
                    break;
                }
            }
        }
        return t;
    }
};