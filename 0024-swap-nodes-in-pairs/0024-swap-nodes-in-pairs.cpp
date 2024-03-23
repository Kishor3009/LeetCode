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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* temp=new ListNode(0);
        temp->next=head;
        ListNode* curr=temp;
        while(curr->next!=NULL && curr->next->next!=NULL){
            ListNode* f=curr->next;
            ListNode* s=curr->next->next;
            
            f->next=s->next;
            s->next=f;
            curr->next=s;
            curr=curr->next->next;
        }
        
        return temp->next;
    }
};