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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp=head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* curr=dummy;
        while (curr->next != NULL && curr->next->next != NULL) {
            ListNode* first = curr->next;
            ListNode* second = curr->next->next;
            
            if (first->val == second->val) {
                while (second != NULL && first->val == second->val) {
                    second = second->next;
                }
                curr->next = second;
            } else {
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};