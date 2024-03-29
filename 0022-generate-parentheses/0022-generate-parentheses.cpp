class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>str;
        fun(str,n,0,0,"");
        return str;
    }
    void fun(vector<string>&str,int n,int open,int close,string curr_str){
        if(curr_str.size()==n*2){
            str.push_back(curr_str);
            return;
        }
        if(open<n) fun(str,n,open+1,close,curr_str+"(");
        if(close<open) fun(str,n,open,close+1,curr_str+")");
    }
};