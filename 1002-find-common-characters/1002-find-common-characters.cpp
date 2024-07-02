class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> minFreq(26, INT_MAX);

        for (const string& word : words) {
            vector<int> charCount(26, 0);
            for (char c : word) {
                charCount[c - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                minFreq[i] = min(minFreq[i], charCount[i]);
            }
        }

        vector<std::string> result;
        for (int i = 0; i < 26; ++i) {
            if (minFreq[i] != INT_MAX && minFreq[i] > 0) {
                for (int j = 0; j < minFreq[i]; ++j) {
                    result.push_back(std::string(1, 'a' + i));
                }
            }
        }

        return result;
    }
};