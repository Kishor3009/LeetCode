class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> scores;
    
        for (const string& op : ops) {
            if (op == "+") {
                if (scores.size() >= 2) {
                    int newScore = scores[scores.size() - 1] + scores[scores.size() - 2];
                    scores.push_back(newScore);
                }
            } else if (op == "D") {
                if (!scores.empty()) {
                    scores.push_back(2 * scores.back());
                }
            } else if (op == "C") {
                if (!scores.empty()) {
                    scores.pop_back();
                }
            } else {
                scores.push_back(stoi(op));
            }
        }
    
    int totalScore = 0;
    for (int score : scores) {
        totalScore += score;
    }
    
    return totalScore;
    }
};