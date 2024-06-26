class Solution {
public:
    bool check(vector<int> &v,int &k){
        for(auto &i: v){
            if(i<k)return true;
        }
        return false;
    }
    int takeCharacters(string s, int k) {
        
        vector<int>v(3,0);
        for(auto &i:s){
            v[i-'a']++;
        }
        if(check(v,k)){
            return -1;
        }
        int ans=0,i=0,j=0;
        int n=s.length();
        while(i<n){
            v[s[i]-'a']--;
            while(check(v,k)){
                v[s[j]-'a']++;
                j++;
            }
            ans=max(i-j+1,ans);
            i++;
        }
        return s.length()-ans;
    }
};