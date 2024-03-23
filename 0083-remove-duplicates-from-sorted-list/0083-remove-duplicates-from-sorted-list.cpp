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
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(head==NULL || head->next==NULL) return head;

        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* curr=dummy;
        while (curr->next != NULL && curr->next->next != NULL) {
            ListNode* first = curr->next;
            ListNode* second = curr->next->next;
            
            if (first->val == second->val) {
                
                curr->next = first->next;
            } else {
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};