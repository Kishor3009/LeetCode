class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
         unordered_map<string, int> mp; 
        for (const auto& it : arr) {
            mp[it]++;
        }
        for (const auto& i : arr) { 
            if (mp[i] == 1) {
                k--;
            if (k == 0) return i;
            }
        }
        return "";
    }
};