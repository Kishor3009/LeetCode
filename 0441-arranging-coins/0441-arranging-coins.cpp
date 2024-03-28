class Solution {
public:
    int arrangeCoins(int n) {
        if(n==0) return 0;
        int k=0;
        int tot=1;
        while(n>=0){
            n=n-tot;
            tot++;
            k++;
        }
        return k-1;
    }
};