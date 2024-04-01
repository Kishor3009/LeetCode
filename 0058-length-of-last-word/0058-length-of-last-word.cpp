#include <bits/stdc++.h>
class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(), s.end()); 
        int i = 0;
        int c = 0;
        // Find the first non-space character
        while (i < s.size() && s[i] == ' ') {
            i++;
        }
        // Calculate the length of the last word
        while (i < s.size() && s[i] != ' ') {
            c++;
            i++;
        }

        return c;
    }
};