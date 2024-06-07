class Solution {
public:
    string replaceWords(vector<string>& dict, string s) {
        unordered_map<string,int>mp;
        for(auto it:dict){
            mp[it]++;
        }
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++){
            bool check=1;
            string temp="";
            while(i<n && s[i]!=' '){
                temp+=s[i];
                if(mp.count(temp) && check){
                    ans+=temp+" ";
                    check=0;
                }
                i++;
            }
            if(check){
                ans+=temp+" ";
            }
        }
        int siz=ans.size();
        return ans.substr(0,siz-1);
    }
};