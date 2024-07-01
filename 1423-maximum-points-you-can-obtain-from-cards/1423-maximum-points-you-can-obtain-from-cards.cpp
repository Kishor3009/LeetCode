class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n = card.size();
        
        int current_sum = 0;
        for (int i = 0; i < k; ++i) {
            current_sum += card[i];
        }
        
        int max_sum = current_sum;
        
        for (int i = 0; i < k; ++i) {
            current_sum = current_sum - card[k - 1 - i] + card[n - 1 - i];
            max_sum = max(max_sum, current_sum);
        }
        
        return max_sum;
    }
};