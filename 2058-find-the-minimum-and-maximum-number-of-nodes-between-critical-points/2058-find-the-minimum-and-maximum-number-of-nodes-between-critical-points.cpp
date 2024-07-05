/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* k = head;
        ListNode* temp = head->next;
        vector<int> criticalPoints;
        vector<int> result(2, -1);
        int index = 2;  
        if (head == nullptr || head->next == nullptr 
            || head->next->next == nullptr) return result;

        while (temp->next != nullptr) {
            if (((temp->val > k->val) && (temp->val > temp->next->val)) ||
                ((temp->val < k->val) && (temp->val < temp->next->val))) {
                criticalPoints.push_back(index);
            }
            temp = temp->next;
            k = k->next;
            index++;
        }

        if (criticalPoints.size() < 2) {
            return result; 
        }
    int minDist = INT_MAX;
    for (int i = 1; i < criticalPoints.size(); ++i) {
        minDist = min(minDist, criticalPoints[i] - criticalPoints[i - 1]);
    }

    int maxDist = criticalPoints.back() - criticalPoints.front();

    result[0] = minDist;
    result[1] = maxDist;

    return result;
    }
};