class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int freq[200001]={0}, y=1e5, n=nums.size();
        for(int x:nums){
            freq[x]++;
            y=min(x,y);
        }
        int cnt=0,inc=0;
        for(int x=y;cnt<n;x++){
            int f=freq[x];
            cnt+=(f!=0);
            if(f<=1) continue;
            freq[x+1]+=(f-1);
            inc+=(f-1);
        }
        return inc;
    }
};