class Solution {
public:
    int minBitFlips(int s, int g) {
        int ans=s^g;
        int c=0;
        for(int i=0;i<31;i++){
            if(ans&(1<<i)){
                c++;
            }
        }
        return c;
    }
};