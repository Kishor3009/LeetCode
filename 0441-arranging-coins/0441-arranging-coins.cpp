class Solution {
public:
    int arrangeCoins(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(n==1) return 1;
        //int k=0;
        int tot=1;
        while(n>=tot){
            n=n-tot;
            tot++;
            //k++;
        }
        return tot-1;
    }
};