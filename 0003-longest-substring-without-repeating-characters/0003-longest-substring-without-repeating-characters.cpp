class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        if(n==0) return 0;
        int m=0;
        int k=0,j=0;
        for(int i=0;i<n;i++){
            if(mp[s[i]]==0){
                mp[s[i]]++;
                k++;
                m=max(m,k);
            }
            else{
                m=max(m,k);
                while(j<i && mp[s[i]]>0){
                    mp[s[j]]--;
                    j++;
                    k--;
                }
                k++;
                m=max(m,k);
                mp[s[i]]++;
            }
           
        }
        m=max(m,k);
        return m;
    }
};