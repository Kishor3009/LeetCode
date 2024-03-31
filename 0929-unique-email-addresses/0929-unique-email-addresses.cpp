class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int n=emails.size();
        unordered_set<string>st;
        for(auto mail:emails){
            string cemail;
            for(char c:mail){
                if(c=='@' || c=='+') break;
                if(c=='.') continue;
                cemail+=c;
            }
            cemail+=mail.substr(mail.find('@'));
            st.insert(cemail);
        }
        return st.size();
    }
};