class Solution {
public:
    bool isSubsequence(string s, string t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int pos=0;
        for(int i=0;i<t.size();i++){
            if(t[i]==s[pos]) pos++;
        }
        return pos==s.size();
    }
};