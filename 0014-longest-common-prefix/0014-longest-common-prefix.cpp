class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        string s="";
        sort(strs.begin(),strs.end());
        int n=strs.size();
        string f=strs[0],l=strs[n-1];
        for(int i=0;i<min(f.length(),l.length());i++){
            if(f[i]!=l[i]){
                return s;
            }
            s+=f[i];
        }
        return s;
            }
};