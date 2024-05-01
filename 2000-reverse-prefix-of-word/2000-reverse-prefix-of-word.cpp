class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n=word.size();
        string s="";
        int f=0;
        for(int i=0;i<n;i++){
            if(word[i]==ch){
                s+=word[i];
                f=1;
                break;
            }
            else{
                s+=word[i];
            }
        }
        if(f==0) return word;
        reverse(s.begin(),s.end());
        int k=s.size();
        int i=0;
        while(k>0){
            word[i]=s[i];
            i++;
            k--;
        }
        return word;
    }
};