class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int res = 0;
        string top, bot;
        int ts, bs;

        if (y > x) {
            top = "ba";
            ts = y;
            bot = "ab";
            bs = x;
        } else {
            top = "ab";
            ts = x;
            bot = "ba";
            bs = y;
        }
        vector<char> st;
        for (char ch : s) {  
            if (ch == top[1] && !st.empty() && st.back() == top[0]) {
                res += ts;
                st.pop_back();
            } else {
                st.push_back(ch);
            }
        }
        vector<char> nst;
        for (char ch : st) { 
            if (ch == bot[1] && !nst.empty() && nst.back() == bot[0]) {
                res += bs;
                nst.pop_back();
            } else {
                nst.push_back(ch);
            }
        }

        return res;
    }
};