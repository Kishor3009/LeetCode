class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs;
        int m = difficulty.size();
        
        for (int i = 0; i < m; ++i) {
            jobs.emplace_back(difficulty[i], profit[i]);
        }
        
        sort(jobs.begin(), jobs.end());
        
        sort(worker.begin(), worker.end());
        
        int maxProfit = 0, jobIndex = 0, n = worker.size();
        int result = 0;
        
        for (int i = 0; i < n; ++i) {
            while (jobIndex < m && jobs[jobIndex].first <= worker[i]) {
                maxProfit = max(maxProfit, jobs[jobIndex].second);
                ++jobIndex;
            }
            result += maxProfit;
        }
        
        return result;
    }
};