class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<string,vector<std::string>> anagramGroups;

        for (string& word : strs) {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());
            anagramGroups[sortedWord].push_back(word);
        }

        vector<vector<string>> result;
        for (auto& pair : anagramGroups) {
            result.push_back(pair.second);
        }

        return result;
    }
};