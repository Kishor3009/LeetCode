class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<pair<int, int>> mp;

        for (int num : nums) {
            string numStr = to_string(num);
            string str;

            for (char digit : numStr) {
                int i = digit - '0'; 
                str += to_string(mapping[i]);  
            }

            int rp = stoi(str);  
            mp.push_back({rp, num});
        }

        stable_sort(mp.begin(), mp.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first;
        });
        vector<int> ans;
        for (auto it : mp) {
            ans.push_back(it.second);
        }

    return ans;
    }
};