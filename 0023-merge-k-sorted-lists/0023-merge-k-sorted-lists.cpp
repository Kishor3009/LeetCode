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
struct compare {
    bool operator()(ListNode* l1, ListNode* l2) {
        return l1->val > l2->val;
    }
};
class Solution {
public:
    // bool compare()(ListNode* l1, ListNode* l2){
    //     return l1->val > l2->val;
    // }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare>pq;
        for(ListNode* it:lists){
            if(it) pq.push(it);
        }
        ListNode dummy;
        ListNode* tail = &dummy;
    
        while (!pq.empty()) {
            ListNode* top = pq.top();
            pq.pop();
        
            tail->next = top;
            tail = tail->next;

            if (top->next) {
                pq.push(top->next);
            }
        }
        return dummy.next;
    }
};