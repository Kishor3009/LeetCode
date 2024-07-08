class Solution {
public:
    int findTheWinner(int n, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        deque<int>d;
        for(int i=0;i<n;i++){
            d.push_back(i+1);
        }
        int c=0;
        while(d.size()!=1){
            c++;
            if(c==k){
                d.pop_front();
                c=0;
            }
            else{
                int j = d.front();
                d.pop_front();
                d.push_back(j);
            }
        }
        return d.front();
    }
};