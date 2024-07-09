// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1,h=n;
        while(true){
            int m=l+(h-l)/2;
            if((m==n || m==1) && isBadVersion(m)==true) return m;
            else if((isBadVersion(m)==false) && (isBadVersion(m+1)==true)) return m+1;
            else if((isBadVersion(m)==false)) l=m+1;
            else h=m-1;
        }
        
    }
};