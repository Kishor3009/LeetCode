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
    ListNode* findmiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=nullptr;
        ListNode* nxt=head;
        while(curr!=NULL){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if (head == nullptr || head->next == nullptr) return;
        
        ListNode* middle = findmiddle(head);
        ListNode* secondHalf = middle->next;
        middle->next = nullptr; 
        secondHalf = reverse(secondHalf);
        
        ListNode* first = head;
        while (secondHalf != nullptr) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = secondHalf->next;
            first->next = secondHalf;
            secondHalf->next = temp1;
            first = temp1;
            secondHalf = temp2;
        }
    }
};