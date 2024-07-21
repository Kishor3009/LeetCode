class Solution {
public:
    int countVowels(string& s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int count = 0;
    
        for (char c : s) {
            if (vowels.find(c) != vowels.end()) {
                count++;
            }
        }
    
        return count;
    }
    
    bool doesAliceWin(string& s) {
        int n = s.length();
        int t=countVowels(s);
        if(t==0) return false;
        return true;
    
    }
};