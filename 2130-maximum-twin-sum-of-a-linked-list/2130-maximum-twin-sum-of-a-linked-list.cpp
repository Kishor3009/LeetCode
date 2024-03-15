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
    int pairSum(ListNode* head) {
        if(head->next==NULL) return head->val;
        ListNode* middle=findmiddle(head);
        ListNode* h2=reverse(middle->next);
        middle->next=NULL;
        ListNode* h1=head;
        int maxi=0;
        while(h2!=NULL){
            maxi=max(maxi,h1->val+h2->val);
            h1=h1->next;
            h2=h2->next;
        }
        return maxi;
    }
};